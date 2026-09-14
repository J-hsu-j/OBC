#!/bin/bash

# Define the path to the 'hsmgen' directory relative to the current script's location.
GEN_PATH=../../../lib/libhsm/hsmgen

# Run the Python script with the specified configuration and output paths.
python "$GEN_PATH/hsmgen.py" --conf telemetry_sm.yaml --outpath . --templatepath "$GEN_PATH"
python "$GEN_PATH/hsmgen.py" --conf telemetry_file_sink_sm.yaml --outpath . --templatepath "$GEN_PATH"