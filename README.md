# EnduroSat OBC_STDPF – PAY1(UART6) 0xAA TX bench test

這份 README 說明本次為了「快速驗證 PAY1(UART6) 能持續送資料到 payload / RS-422/RS-485 transceiver」而做的程式更動、原因與使用方式。

> 本功能是 **bench test**（示波器/LA 量測用），不是正式通訊堆疊的一部分。

## 目標（你要看到什麼結果）

- 開機後建立一個低優先序 thread。
- 透過 **USART6** 持續送出 pattern `0xAA`（預設 115200 8N1）。
- 並把 PAY1 端的 transceiver 控制腳拉到「可發送」狀態：
  - `DE` 拉高（driver enable）
  - `nRE` 拉低（receiver enable）

## 變更總覽（做了哪些事）

### 1) 新增 `espf/app/payload_communication.c`

用途：
- 實作 `payload_communication_start()`，在 while(1) 裡反覆送 `0xAA`。
- 使用 `HAL_UART_Transmit_IT()`（中斷式 TX），避免長時間 blocking。
- 實作 `HAL_UART_TxCpltCallback()` 來清 `busy` 旗標。
- 透過 `MCU_Init.h` 既有的 PAY1 定義，初始化 DE / nRE：
  - `RS422_HS2_DE_UART6_PAY1`：PF10
  - `RS422_HS2_nRE_UART6_PAY1`：PF12

為什麼需要：
- 需求是「在 app 層快速驗證 UART6 送出波形/資料」；最直覺做法就是 app 層獨立一個小模組，只做送資料。

**重要注意**：這個檔案整段行為都被 `#if defined(PAYLOAD_UART6_TX_TEST)` 包住。

### 2) 修改 `espf/config/arch/stm32h753iit/stm32h7xx_hal_msp.c`

新增：USART6 的 HAL MSP init/deinit 分支。

做了什麼：
- 開 USART6 clock + 選擇 USART6 的 kernel clock source。
- 設定 USART6 的 GPIO alternate function：
  - PC6 → USART6_TX
  - PC7 → USART6_RX
- 打開 NVIC：`USART6_IRQn` priority=5。

為什麼需要：
- `HAL_UART_Init()` 會呼叫 `HAL_UART_MspInit()`。
- 如果 MSP 沒有 USART6 分支：
  - USART6 時鐘不會開
  - TX pin 不會切到 AF
  - NVIC 不會 enable
  - 結果就是「程式看起來在送，但 pin 上沒有任何 UART 波形」，或中斷式 TX 直接卡住。

### 3) 修改 `espf/config/arch/stm32h753iit/UnhandledISRs.c`

新增真正的 `USART6_IRQHandler()`（不再是 weak 版本）。

做了什麼：
- 當 `PAYLOAD_UART6_TX_TEST` 有開時：
  - `USART6_IRQHandler()` 會呼叫 `HAL_UART_IRQHandler(&g_payload_uart6)`
- 當沒開：
  - 維持原邏輯，直接進 `Error_Handler()`（避免默默吞中斷，保留既有安全行為）

為什麼需要：
- 本專案把很多未實作的 IRQ handler 都集中在 `UnhandledISRs.c` 用 weak 版本兜底。
- 如果不覆寫 USART6 IRQ：
  - 一旦 USART6 觸發中斷，就會進 `Error_Handler()`（等於系統直接進錯誤處理）。
- 中斷式 TX 必須要 IRQ handler 進 HAL 才能呼叫 `TxCpltCallback` 完成一次送出。

### 4) 修改 `espf/app/init_service/AppTasks.c`

新增：`PayU6Tx` thread（只有在 `PAYLOAD_UART6_TX_TEST` 開啟時才建立）。

做了什麼：
- 在 `AppTask_Init()` 裡建立 thread，entry 直接呼叫 `payload_communication_start()`。

為什麼需要：
- `payload_communication_start()` 是 while(1) 的測試 loop。
- 如果把它直接塞到 `main()` 或現有 task 的 init 流程，可能會阻塞既有系統。
- 用獨立 thread 可以：
  - 不影響原本 app 主 task 的週期性工作
  - 方便用 macro 一鍵開關

### 5) 修改 `espf/app/CMakeLists.txt`

新增：把 `payload_communication.c` 加到 `OBC_sources`。

為什麼需要：
- 沒有加入 sources，檔案不會被編進去，`payload_communication_start()` 也就不存在（link 會失敗或功能不生效）。

> 你有手動編輯過這個檔案；目前內容確認仍有把 `payload_communication.c` 加進 `OBC_sources`，這是正確的。

## 如何啟用 / 停用

本功能透過 compile-time macro 控制：

- **啟用**：定義 `PAYLOAD_UART6_TX_TEST`
- **停用**：不要定義它（預設）

### 建議的啟用方式（兩種擇一）

1) 在對應的全域 compile definitions（CMake 的 target compile definitions）加入 `PAYLOAD_UART6_TX_TEST`
2) 或在專案的全域設定 header 裡 `#define PAYLOAD_UART6_TX_TEST`（較不推薦，容易忘記）

> 目前 repo 內「macro 應該放哪裡」取決於你們現有的 build convention；我可以再幫你找最乾淨的放置點，並直接把它接到 debug / release profile。

## 量測/驗證重點

- UART6 TX：PC6（AF7 USART6）
- UART6 RX：PC7（本測試僅 TX，RX 不一定會用到）
- PAY1 transceiver control：
  - PF10：DE
  - PF12：nRE

如果你看到 UART6 TX 沒波形，優先檢查：
- `PAYLOAD_UART6_TX_TEST` 是否真的有進到編譯（看 map / obj / 或在 code 加 log/LED）。
- PC6 是否確實接到 payload driver/transceiver。
- DE/nRE 的有效極性是否跟假設相同：本測試假設 `DE=1` 啟用、`nRE=0` 啟用。

## 風險與回復方式

- 風險：如果啟用 macro，UART6 會一直送資料，可能影響 payload 端通訊/功耗。
- 回復：移除 `PAYLOAD_UART6_TX_TEST` compile definition，即可完全不編譯該功能（ISR 也會回到 Error_Handler 行為）。
