import re
from pathlib import Path
import sys
import argparse

def parse_file(file_path : Path) -> list[str]:
    dc_struct_list = []
    try:
        with open(file_path, "r") as dc_file:
            for line in dc_file:
                m = re.match(r"} PACKED_STRUCT (DATA_CACHE_[A-Za-z0-9_-]+)", line)
                if m != None:
                    dc_struct_list.append(m.group(1))
    except FileNotFoundError:
        print(f"Error: The file at {dc_file} was not found.")
        sys.exit(1)
    except IOError as e:
        print(f"Error: An I/O error occurred. {e}")
        sys.exit(1)

    return dc_struct_list


static_check_list: str = '@@@ STATIC_CHECK_LIST @ @@'
file_template: str = f"""/*
 * Copyright (c) EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 * -----------------------------------------------------------------------------
 * This is a generated file. Do not modify manually as the changes may be
 * overwritten.
 * -----------------------------------------------------------------------------
 */

#include <assert.h>
#include "datacache.h"
#include "telemetry_cfg_defs.h"
#include "telemetry_types.h"

// the worst case size calculation for telemetry COBS-encoded frames includes:
// 1) tlm_frame_hdr_t (telemetry frame header)
// 2) the DataCache structure bytes
// 3) tlm_msg_footer_t (telemetry frame footer)
// 4) COBS-overhead for delimiters which is 1 additional length byte for every 254 non-zero bytes
#define WORST_CASE_SZ_FOR_DC_ATTR(struct_name)	(sizeof(tlm_frame_hdr_t) + sizeof(struct_name) + sizeof(tlm_msg_footer_t) + ((sizeof(struct_name) / 254))) 

{static_check_list}
"""

def gen_checker_code(dc_struct_list : list[str]):
    return file_template.replace(static_check_list, '\n'.join(map(lambda dc_struct_name: f'static_assert(WORST_CASE_SZ_FOR_DC_ATTR({dc_struct_name}) <= TLM_BUF_SIZE);', dc_struct_list)))

# Create the parser
parser = argparse.ArgumentParser(
    description="This script generates a C file which performs static checks on the size of the individual data cache items fitting in the telemetry queue."
)

# Add arguments
parser.add_argument("dc_h_file_path", type=str, help="Path to the generated datacache.h file")
parser.add_argument("out_c_file_path", type=str, help="Path and name of the generated output .c file")

# Parse the arguments
args = parser.parse_args()

# Access the arguments
dc_h_file_path = args.dc_h_file_path
out_c_file_path = args.out_c_file_path

if (dc_h_file_path == None) or (out_c_file_path == None):
    print(parser.print_help())
    sys.exit(1)

dc_struct_list = parse_file(args.dc_h_file_path)

try:
    with open(args.out_c_file_path, "w") as gen_file:
        gen_file.write(gen_checker_code(dc_struct_list))
except IOError as e:
    print(f"Error: An I/O error occurred. {e}")
    sys.exit(1)

print(f'"{Path(args.out_c_file_path).resolve()}" generated successfully.')
sys.exit(0)
