def mkfs(bdev_in : str) -> None:
    """
    Perform a format of the OBC file system on the external SD card.

    The function is blocking and will take some time before it returns control.

    Parameters
    ----------
    :param bdev_in: Currently this parameter is unused since the OBC supports only one hard-coded block device.
                    The parameter is reserved for future use so you can pass here an empty string.
    """
    pass


def listdir(path : str) -> list[str]:
    """
    List the names of the entries in the directory given by path.

    This VFS (Virtual File System) function returns a list containing the names of the entries
    in the directory specified by the `path` argument. The list is in arbitrary order and does
    not include the special entries '.' (current directory) and '..' (parent directory) even
    if they are present in the directory.

    Parameters:
    - path (str): A path-like object representing the file system path. If `path` is not provided,
                  the function uses the current working directory ('.'). The path must point to
                  a directory; otherwise, an appropriate exception will be raised.

    Returns:
    - list: A list of the entry names (str) in the directory given by `path`. The list can be empty
            if there are no entries or if the directory does not exist.

    Example:

        >>> listdir('/tmp')
        ['file1.txt', 'file2.txt', 'subdir']

        This example lists the entries in the '/tmp' directory.

    """
    pass  # The implementation would list directory contents here.


def mkdir(path : str) -> None:
    """
    Create a new directory at the specified path.

    This function creates a directory named `path`.

    Parameters:
    - path (str): The path where the new directory will be created.

    Returns:
    - None

    Example:

        >>> mkdir('/tmp/newdir')

        This creates a new directory named 'newdir' in the '/tmp' directory.

    Note:
    - The actual creation of the directory may depend on the underlying filesystem and its
      capabilities.

    """
    pass


def rmdir(path : str) -> None:
    """
    Remove (delete) the directory path.

    This function deletes the directory specified by `path`. The directory must be empty,
    otherwise, an error is raised.

    Parameters:
    - path (str): The path to the directory to be deleted.

    Returns:
    - None

    Example:

        >>> rmdir('/tmp/emptydir')

        This deletes the empty directory named 'emptydir' located in the '/tmp' directory.

    Note:
    - This function only works on empty directories. To remove non-empty directories, additional
      logic to delete the directory contents must be implemented.

    """
    pass

def rename(old_path : str, new_path : str) -> None:
    """
    Rename a file or directory from `old_path` to `new_path`.

    This function changes the name or location of a file or directory from `old_path` to `new_path`.
    If `new_path` exists, the operation may fail or replace `new_path`, depending on the filesystem
    and settings.

    Parameters:
    - old_path (str): The current path of the file or directory.
    - new_path (str): The new path of the file or directory.

    Returns:
    - None

    Raises:
    - FileNotFoundError: If `old_path` does not exist.
    - FileExistsError: If `new_path` already exists and cannot be replaced.
    - PermissionError: If the operation lacks necessary permissions.

    Example:

        >>> rename('/tmp/oldname', '/tmp/newname')

        This renames or moves 'oldname' to 'newname' within the '/tmp' directory.

    """
    pass


def stat(path : str) -> tuple[int, int, int, int, int, int, int, int, int, int]:
    """
    Retrieve status information of the specified path.

    This function returns information about the specified path, such as size, modification time,
    and access permissions. The information returned is system and filesystem dependent.

    Parameters:
    - path (str): The path to retrieve information for.

    Returns: a tuple containing the following integer fields in the specified order:
             [st_mode, st_ino, st_dev, st_nlink, st_uid, st_gid, st_size, st_atime, st_mtime, st_ctime]

    """
    pass


def statvfs(path : str) -> tuple[int, int, int, int, int, int, int, int, int, int]:
    """
    Retrieve filesystem status and information.

    This function provides information related to the filesystem containing the given path, such
    as block size, total blocks, free blocks, and available blocks for non-superusers.

    Parameters:
    - path (str): The path whose filesystem information is to be queried.

    Returns: A tuple containing the following integer fields in the specified order:
             [f_bsize, f_frsize, f_blocks, f_bfree, f_bavail, f_files, f_ffree, f_favail, f_flags, f_namemax]

    Note:
    - This function can be particularly useful for determining the capacity and availability of
      storage space on the filesystem where `path` resides.

    """
    pass
