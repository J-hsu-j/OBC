# File Tools

## Introduction

The file tools library is a file management API.
It provides a simplified interface to the underlying file systems and storage devices used by the MCU.

The conceptual organization is based on the idea that there is a drive or volume which is a combination of a file system and a storage device.
The volume is addressed by a path prefix, which from the standard point of view is just a top-level directory. For example the fatfs on the SD card is addressed with the "/sd" prefix and if one would want to open a file in that volume, it would be like this:
```C
fm_open(handle, "/sd/file.txt", FM_MODE_READ);
```

The implementation takes care of all the low-level details. The user has not direct access to the file system or storage device.
All the API functions return the same type of result variable, which makes error checking standard.

A lot of the functions and types are self-explanatory. This document will describe the more non-intuitive aspects of the API, give a short overview and also give examples for typical usage. The reader is expected to have knowledge of the standard C programming language and basic understanding of a typical file system (like what is a file or a directory, file access, file position etc.). No additional knowledge of the OBC or related software is required.

### Header files

The API methods are defined in "fm_mng.h".
There are two more file tools API's which are built on top of "fm_mng.h" - "rlf.h" and "stack_file.h".  
"rlf.h" is a rolling file implementation.
"stack_file.h" is a fixed item size container using the file system as memory instead of the RAM. It is useful for slow memory intensive FIFO operations.
"sd_hook.h" is used to expose a notification function for the interrupt vector used for detecting changes on the SD card(s) detection pin(s) (SDMMC1/2_DET). It should not be used for any other purpose.

## Memory
Allocation of file objects can be done either by the caller, or internally by the fm_mng.h.
### Allocation by the caller:

Example 1:
```C
fs_file_obj_t file_obj;
fm_open(&file_obj, "/vol/file.txt", FM_MODE_READ);
```

Example 2:
```C
fm_handle_t handle = malloc(sizeof(fs_file_obj_t));
fm_open(handle, "/vol/file.txt", FM_MODE_READ);
```

The caller is responsible for deallocation after closing.

### Allocation by fm_mng
```C
fm_handle_t handle;
fm_open_internal(&handle, "/vol/file.txt", FM_MODE_READ); // notice the reference operator
```

## fm_mng.h

### Types

1. Typical types:  
    These are standard types used in the C language and do not require further description:
    `bool`, zero-terminated ascii char string (`char*`, `char[]`), byte buffers(`uint8_t*`,`uint8_t[]`), `uint32_t`
1. `fm_file_obj_t`  
    This is not a directly usable type but a placeholder object which is the size of the internally used file object by `fm_mng.h` functions. The fm_file_obj_t is used to be allocated in the stack (or elsewhere) by the caller.
1. `fm_handle_t`  
    This type is a pointer to an fm_file_obj_t, but it may point to an internal object of fm_mng.h
1. `storage_status_t`  
    This enum type presents the status of the storage device. The different values are described in-code.
1. `fm_mode_t`  
    Enum type which values are bit fields which may be combined to determine access mode when opening a file. `READ` and `WRITE` may be combined freely. The only one of the other modes is allowed (except `OPEN_EXISTING` which being 0 is ignored when other OPEN/CREATE modes are applied).
1. `fm_dir_obj_t`  
    Same as `fm_file_obj_t` but relates to directories. See `fm_dir_xxx` functions.
1. `fm_dir_handle_t`  
    Same as `fm_handle_t` but relates to directories.
1. `fm_file_info_t`  
    File metadata given by the `dir_xxx()` functions. The name parameter contains the full path to the file name except the volume prefix.
1. `fm_temporary_file_info_t`  
    File metadata returned by a foreach directory iteration function (e.g. `fm_foreach_flat()`, `fm_foreach()`). The `p_path` contains the path to the file except the volume prefix. `p_name` is the basename of the file.
1. `fm_result_t`  
    The commont result type returned by all fm_mng.h methods. It is orthogonal to FRESULT which is described in ff.h which is the fatfs implementation from <elm-chan.org>. The FRESULT has been deemed descriptive enough to provide common error codes for the currently used file systems.

## Examples

1. The most basic write to a file:
    ```C
    fm_file_obj_t file_obj;
    fm_open(&file_obj, "file.txt", FM_MODE_OPEN_APPEND | FM_MODE_WRITE);
    fm_write(&file_obj, "Some new text data\n", 19, NULL);
    fm_close(&file_obj);
    ```
1. A basic read from existing file using stack allocated file object:
   ```C
    fm_file_obj_t file_obj;
    fm_result_t fm_res;
    char buffer[1024];
    fm_res = fm_open(&file_obj, "file.txt", FM_MODE_OPEN_EXISTING | FM_MODE_READ);
    if (FM_RES_OK == fm_res)
    {
        size_t bytes_to_read;
        fm_size(&file_obj, &bytes_to_read);
        if (sizeof(bufffer) < bytes_to_read)
        {
            bytes_to_read = sizeof(buffer);
        }
        fm_read(&file_obj, buffer, bytes_to_read, NULL);
        fm_close(&file_obj);
    }

   ```