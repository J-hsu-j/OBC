#!/bin/bash

GEN_PATH="../../../../lib/libhsm/hsmgen"
py "$GEN_PATH/hsmgen.py" --conf sdr_sm.yaml --outpath . --templatepath "$GEN_PATH"
