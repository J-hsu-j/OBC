from sys import argv
import datetime
import os
from struct import unpack_from
from rich import print
import es_crc
import cobs
import datacache


def unixtime_to_readable_date(unix_timestamp: int) -> str:
    date_string = ""

    try:
        date_string = datetime.datetime.fromtimestamp(unix_timestamp).strftime('%Y-%m-%d %H:%M:%S')
    except Exception as exc:
        date_string = "invalid timestamp"

    return date_string


class TelemetryFileHdr:
    HDR_SIZE = 21
    CRC_SIZE = 2

    def __init__(self):
        self.signature = ''
        self.version = 0
        self.next_write_offset = 0
        self.reserved = 0
        self.file_complete = False
        self.crc = 0
        self.calc_crc = 0
        self.is_crc_valid = False

    def parse(self, data: bytes) -> int:
        if len(data) >= TelemetryFileHdr.HDR_SIZE:
            (
                self.signature,
                self.version,
                self.next_write_offset,
                self.reserved,
                self.file_complete,
                self.crc,
            ) = unpack_from("<6sLLL?H", data)
            # skip CRC bytes...
            self.calc_crc = es_crc.crc_util.crc16(data[: -TelemetryFileHdr.CRC_SIZE])

            self.is_crc_valid = (self.crc == self.calc_crc)

            return TelemetryFileHdr.HDR_SIZE if self.is_crc_valid else 0
        else:
            return 0

    def is_valid(self) -> bool:
        return self.is_crc_valid

    def __str__(self):
        return f'TelemetryFileHdr> signature: {self.signature} | ver: 0x{self.version:04x} | next_write_offset: {self.next_write_offset} | reserved: 0x{self.reserved:08x} | complete: {self.file_complete} | crc: {hex(self.crc)} | is_valid: {self.is_crc_valid} | calc_crc: {hex(self.calc_crc)}'

class TelemetryMsgBase:
    CRC_SIZE = 2
    MAX_TLM_ROLL_FRAME_CNT = 256

    def __init__(self, msg_id: int):
        self.HDR_SIZE = 11
        self.timestamp = 0
        self.timestamp_precise = 0
        self.rolling_cntr = 0
        self.obc_opmode = 0
        self.msg_type = 0
        self.tlm_data_status = False
        self.data = []
        self.data_len = 0
        self.crc = 0
        self.calc_crc = 0
        self.is_crc_valid = False
        self.total_len = 0
        self.msg_id = msg_id
        self.str_from_parsed_dict = ""

    def _print_reply(self, dict_mac_reply, ident=8):
        str_space_val = "  ".ljust(ident)
        for key, value in dict_mac_reply.items():
            if (type(value) is list and "libs.mac" in str(value)) or (
                type(value) is list and "libs.fidl" in str(value)
            ):
                for item in value:
                    attribute_dict = vars(item)
                    self._print_reply(attribute_dict, ident + 2)
            else:
                self.str_from_parsed_dict += (
                    f"{str_space_val}{key:<22}:           {value}\n"
                )

    def parse(self, data: bytes) -> int:
        if len(data) < self.HDR_SIZE:
            self.total_len = 0
            return 0

        # Unpack the data
        (
            self.timestamp,
            self.timestamp_precise,
            self.rolling_cntr,
            self.obc_opmode,
            self.msg_type,
            self.tlm_data_status,
            self.data_len,
        ) = unpack_from("<LHBBHBH", data)

        for b in data[
            self.HDR_SIZE : self.HDR_SIZE + self.data_len
        ]:
            self.data.append(b)

        self.crc = unpack_from(
            "<H",
            data[
                self.HDR_SIZE
                + self.data_len : self.HDR_SIZE
                + self.data_len
                + TelemetryMsgBase.CRC_SIZE
            ],
        )[0]

        # skip CRC bytes...
        self.calc_crc = es_crc.crc_util.crc16(data[: -TelemetryMsgBase.CRC_SIZE])

        self.is_crc_valid = self.crc == self.calc_crc

        self.total_len = self.HDR_SIZE + self.data_len + TelemetryMsgBase.CRC_SIZE

        return (self.total_len) if self.is_crc_valid else 0

    def is_valid(self) -> bool:
        return self.is_crc_valid

    def deserialize(self, parser, verbose: bool = True) -> str:
        printout: str = ""

        # Deserialize the data only if there is any
        if len(self.data) > 0:
            (deser_data, bytes_cnt) = parser.parse_by_id(self.msg_type, self.data)
            printout = f"deserialized data [{bytes_cnt}] -> [{deser_data}]" + os.linesep

            if verbose:
                self._print_reply(deser_data.__dict__)
                printout += (self.str_from_parsed_dict) + os.linesep
                self.str_from_parsed_dict = ""

        return printout

    def __str__(self):
        str_repr = f"{self.msg_id} => TelemetryMsgHdr> [{self.total_len}] timestamp: {unixtime_to_readable_date(self.timestamp)} | rollcntr: {self.rolling_cntr} | obc_opmode: {self.obc_opmode} | msg_type: {hex(self.msg_type)} | data_status: {self.tlm_data_status} | len: {self.data_len} | crc: {self.crc} | is_crc_valid: {self.is_crc_valid} | calc_crc: {self.calc_crc}"
        str_repr = (
            str_repr + os.linesep + "\t" + self.deserialize(datacache.dc_parser())
        )

        return str_repr

class TelemetryMsg_v0101(TelemetryMsgBase):
    """This is the first version of the telemetry frame which supports only 1-sec-precision Unix timestamps"""
    def parse(self, data: bytes) -> int:
        if len(data) < self.HDR_SIZE:
            self.total_len = 0
            return 0

        # Unpack the data
        (
            self.timestamp,
            self.rolling_cntr,
            self.obc_opmode,
            self.msg_type,
            self.tlm_data_status,
            self.data_len,
        ) = unpack_from("<LBBHBH", data)

        for b in data[self.HDR_SIZE : self.HDR_SIZE + self.data_len]:
            self.data.append(b)

        self.crc = unpack_from(
            "<H",
            data[
                self.HDR_SIZE
                + self.data_len : self.HDR_SIZE
                + self.data_len
                + TelemetryMsgBase.CRC_SIZE
            ],
        )[0]

        # skip CRC bytes...
        self.calc_crc = es_crc.crc_util.crc16(data[: -TelemetryMsgBase.CRC_SIZE])

        self.is_crc_valid = self.crc == self.calc_crc

        self.total_len = self.HDR_SIZE + self.data_len + TelemetryMsgBase.CRC_SIZE

        return (self.total_len) if self.is_crc_valid else 0

    def __str__(self):
        str_repr = f"{self.msg_id} => TelemetryMsgHdr> [{self.total_len}] timestamp: {unixtime_to_readable_date(self.timestamp)} | rollcntr: {self.rolling_cntr} | obc_opmode: {self.obc_opmode} | msg_type: {hex(self.msg_type)} | data_status: {self.tlm_data_status} | len: {self.data_len} | crc: {self.crc} | is_crc_valid: {self.is_crc_valid} | calc_crc: {self.calc_crc}"
        str_repr = (
            str_repr + os.linesep + "\t" + self.deserialize(datacache.dc_parser())
        )

        return str_repr


class TelemetryMsg_v0200(TelemetryMsgBase):
    """This version of the telemetry frame contains a 2-byte sub-second precision timestamp [0.1 ms] in addition to the Unix timestamp"""
    def __init__(self, msg_id: int):
        super().__init__(msg_id)
        self.HDR_SIZE = 13  # the frame header is 2 bytes longer due to additional high-precision timestamp

    def parse(self, data: bytes) -> int:
        if len(data) < self.HDR_SIZE:
            self.total_len = 0
            return 0

        # Unpack the data
        (
            self.timestamp,
            self.timestamp_precise,
            self.rolling_cntr,
            self.obc_opmode,
            self.msg_type,
            self.tlm_data_status,
            self.data_len,
        ) = unpack_from("<LHBBHBH", data)

        for b in data[
            self.HDR_SIZE : self.HDR_SIZE + self.data_len
        ]:
            self.data.append(b)

        self.crc = unpack_from(
            "<H",
            data[
                self.HDR_SIZE
                + self.data_len : self.HDR_SIZE
                + self.data_len
                + TelemetryMsgBase.CRC_SIZE
            ],
        )[0]

        # skip CRC bytes...
        self.calc_crc = es_crc.crc_util.crc16(data[: -TelemetryMsgBase.CRC_SIZE])

        self.is_crc_valid = self.crc == self.calc_crc

        self.total_len = (
            self.HDR_SIZE + self.data_len + TelemetryMsgBase.CRC_SIZE
        )

        return (self.total_len) if self.is_crc_valid else 0

    def __str__(self):
        str_repr = f"{self.msg_id} => TelemetryMsgHdr> [{self.total_len}] timestamp: {unixtime_to_readable_date(self.timestamp)}.{self.timestamp_precise:04d} | rollcntr: {self.rolling_cntr} | obc_opmode: {self.obc_opmode} | msg_type: {hex(self.msg_type)} | data_status: {self.tlm_data_status} | len: {self.data_len} | crc: {self.crc} | is_crc_valid: {self.is_crc_valid} | calc_crc: {self.calc_crc}"
        str_repr = (
            str_repr + os.linesep + "\t" + self.deserialize(datacache.dc_parser())
        )

        return str_repr

class TelemetryFile:
    frame_version_map = { 0x0101 : TelemetryMsg_v0101, 0x0200 : TelemetryMsg_v0200 }

    def __init__(self, fname: str):
        self.fname = fname
        self.msglist = []
        self.invalid_msg_cnt = 0

    @staticmethod
    def get_tlm_msg_obj_for_version(version : int, msg_idx : int):
        if version in TelemetryFile.frame_version_map:
            return TelemetryFile.frame_version_map[version](msg_idx)
        else:
            raise Exception(f'Unsupported telemetry file version: 0x{version:04x}')

    def parse_file(self) -> None:
        fhdr = TelemetryFileHdr()

        f = open(self.fname, "rb")

        fhdr.parse(f.read(TelemetryFileHdr.HDR_SIZE))

        print(fhdr)

        byte = f.read(1)
        msgdata = []
        msg_idx = 0
        prev_rollling_cntr = 0
        first_frame = True

        while byte:
            current_pos = f.tell()

            if byte[0] != 0:
                msgdata.append(byte[0])
            else:
                msgdata.append(0)
                msg = TelemetryFile.get_tlm_msg_obj_for_version(fhdr.version, msg_idx)
                msg_idx += 1
                # print(''.join('{:02X} '.format(b)
                #       for b in msgdata), end='')

                try:
                    msg.parse(cobs.decode(msgdata))
                except Exception as exc:
                    print(f'Oops: Could not parse record -> {exc}')

                if not msg.is_crc_valid:
                    self.invalid_msg_cnt += 1

                if first_frame:
                    prev_rollling_cntr = msg.rolling_cntr
                    first_frame = False
                else:
                    if ((prev_rollling_cntr + 1) % TelemetryMsgBase.MAX_TLM_ROLL_FRAME_CNT) != msg.rolling_cntr:
                        print(f'\n...\n:exclamation_mark: [bold red]dropped frames {prev_rollling_cntr}..{msg.rolling_cntr} [/bold red]\n...\n')

                prev_rollling_cntr = msg.rolling_cntr

                self.msglist.append(msg)

                # Deserialize data and append deser data to the list after the message itself

                msgdata = []

            byte = f.read(1)

        f.close()
        print(f'{len(self.msglist)} messages parsed | invalid count: {self.invalid_msg_cnt}')


if len(argv) > 1:
    try:
        tlm_file = TelemetryFile(argv[1])
        tlm_file.parse_file()

        for msg in tlm_file.msglist:
            print(f'{msg}')
    except Exception as exc:
        print(f'Oops: {exc}')
    except KeyboardInterrupt:
        print("Program interrupted")
else:
    print(f"usage: \n\t{argv[0]} <telemetry file name to parse> <'v' to toggle deserialization>")
