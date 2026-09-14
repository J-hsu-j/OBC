/*
 * payload_communication.h
 *
 * Header for payload communication module (UART6 bench test).
 * Architecture follows uhf_app.h pattern.
 */

#ifndef PAYLOAD_COMMUNICATION_H
#define PAYLOAD_COMMUNICATION_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 初始化 payload communication 模組並建立 RTOS thread
 *        應在 main.c 的 osKernelStart() 之前呼叫
 */
void payload_comm_init(void);

#ifdef __cplusplus
}
#endif

#endif /* PAYLOAD_COMMUNICATION_H */
