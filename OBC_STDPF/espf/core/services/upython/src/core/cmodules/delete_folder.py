import shutil
import os
import sys

def delete_folder_recursively(folder_path):
    if os.path.exists(folder_path) and os.path.isdir(folder_path):
        shutil.rmtree(folder_path)
        print(f"Deleted folder: {folder_path}")
    else:
        print(f"Folder does not exist or is not a directory: {folder_path}")

if len(sys.argv) > 1:
    folder_path = sys.argv[1]
    delete_folder_recursively(folder_path)
else:
    print(f'usage: {sys.argv[0]} <folder path to delete>')
