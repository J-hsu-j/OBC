#!/bin/bash

# Define the list of FIDL files
fidl_files=(
    "CubeADCS_Gen2_CubeComputerControlProgram8.fidl"
    "CubeADCS_Gen2_CubeComputerCommon3.fidl"
    "fdir_srv.fidl"
    "telemetry.fidl"
    "payload_ctrl.fidl"
    "conops.fidl"
    "OBC_CUBEADCS_GEN2.fidl"
    "sdr.fidl"
    "xband_fe.fidl"
)

# Define common parameters
fidl_root="../../../../../fidl" # Replace with the relative path to the FIDL folder
usermod_cmake="micropython.cmake"

# Iterate over the list of FIDL files and execute the command
for fidl_file in "${fidl_files[@]}"; do
    py gen-upy-binding.py --fidl-root "$fidl_root" -f --usermod-cmake "$usermod_cmake" --fidl "$fidl_file"
done
