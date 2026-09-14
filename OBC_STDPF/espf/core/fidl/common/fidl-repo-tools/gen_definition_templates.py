#!/usr/bin/env python

import os
from os import path
import requests
import shutil
import time
import concurrent.futures

url = "https://latte.ground-station.endurosat.com/macchiato?generator=FDEPL&verbose=true"

MAX_PARALLEL_WORKERS = 1
RESULT_FOLDER = "latte-zipresults/"
DEFINITIONS_DIR = "./definitions"
BUNDLE_ZIP_NAME = "fidl_bundle"

os.makedirs(RESULT_FOLDER, exist_ok=True)


def main():
    shutil.make_archive(BUNDLE_ZIP_NAME, "zip", ".")

    file = f"./{BUNDLE_ZIP_NAME}.zip"
    payload = {}
    # send only file name
    file_name = os.path.basename(file)
    files = {
        "file": (file_name, open(file, "rb")),
    }
    headers = {}
    tic = time.perf_counter()
    print(f"Uploading {file} ... {file_name}", end="", flush=True)
    response = requests.request("POST", url, headers=headers, data=payload, files=files)
    print(f"... {response.status_code}", flush=True)
    zip_output = f"{RESULT_FOLDER}result-{file_name}.zip"
    with open(zip_output, "wb") as f:
        f.write(response.content)
    shutil.unpack_archive(zip_output, DEFINITIONS_DIR)
    print(f"Unpacked {zip_output} to {DEFINITIONS_DIR}", flush=True)

    for dir in os.listdir(DEFINITIONS_DIR):
        if "macchiato-generate--gen-fdepl" in dir:
            print(f"{DEFINITIONS_DIR}/{dir}")
            copytree(f"{DEFINITIONS_DIR}/{dir}/", DEFINITIONS_DIR)
            shutil.rmtree(f"{DEFINITIONS_DIR}/{dir}/")
            break

    toc = time.perf_counter()
    print(f"Finished {file} in {toc - tic:0.4f} seconds", flush=True)
    os.remove(file)
    shutil.rmtree(RESULT_FOLDER)
    return True

# Like shutil.copytree but will not overwrite existing files
def copytree(src, dst):
    if not path.exists(dst):
        os.makedirs(dst)
    for item in os.listdir(src):
        s = path.join(src, item)
        d = path.join(dst, item)
        if path.isdir(s):
            copytree(s, d)
        else:
            if not path.exists(d):
                shutil.copy2(s, d)

if __name__ == "__main__":
    main()
