import sys
import argparse
from pathlib import Path
import re
from typing import Callable, List, Tuple, Optional
from jinja2 import Template
import os
import shutil

class fidl_file_info:
    def __init__(self, fidl_name : str):
        self.fidl_path = Path(fidl_name).resolve()
        self.fidl_version = self.parse_fidl_version()
        self.fidl_package_name, self.fidl_if_name = self.parse_fidl_info()

    def parse_fidl_version(self) -> Optional[str]:
        """Parse the version from the FIDL file."""
        version_pattern = re.compile(r"version\s*{\s*major\s*(\d+)\s*minor\s*(\d+)\s*}")
        try:
            with Path(self.fidl_path).open("r") as file:
                for line in file:
                    match = version_pattern.search(line)
                    if match:
                        maj, min = match.groups()
                        return f"{maj}.{min}"
        except Exception as e:
            print(f"Error reading {self.fidl_path}: {e}")
        return None

    def parse_fidl_info(self) -> Tuple[Optional[str], Optional[str]]:
        """Parse package name and interface name from the FIDL file.
        Only matches interface names where the line immediately following the declaration
        opens with '{', accounting for possible empty lines in between.

        :param fidl_path: Path to the FIDL file.
        :return: A tuple containing the package name and interface name if found, else (None, None).
        """
        package_pattern = re.compile(r"package\s+(\S+.*)")
        interface_pattern = re.compile(
            r"^\s*interface\s+(\S+)\s*$\s*^{", re.MULTILINE | re.DOTALL
        )

        package_name = None
        interface_name = None

        try:
            with Path(self.fidl_path).open("r") as file:
                content = file.read()
                package_match = package_pattern.search(content)

                if package_match:
                    package_name = package_match.group(1)

                interface_match = interface_pattern.search(content)
                if interface_match:
                    interface_name = interface_match.group(1)
        except Exception as e:
            print(f"Error reading {self.fidl_path}: {e}")

        return package_name, interface_name

class file_utils:
    @staticmethod
    def convert_to_relative_path(src_path, dest_path):
        # Convert input paths to Path objects and resolve to absolute paths
        src_path = Path(src_path).resolve()
        dest_path = Path(dest_path).resolve()

        # Find the common ancestor
        common_ancestor = os.path.commonpath([src_path, dest_path])
        common_ancestor_path = Path(common_ancestor)

        # Find the relative path from the source to the common ancestor
        src_to_common = src_path.relative_to(common_ancestor_path)

        # Find the relative path from the common ancestor to the destination
        common_to_dest = dest_path.relative_to(common_ancestor_path)

        # Construct the complete relative path
        relative_path = Path(
            *([".."] * len(src_to_common.parts)) + list(common_to_dest.parts)
        )

        return str(relative_path)

    @staticmethod
    def create_upy_dir(
        name: str,
        path: str,
        force_generate : bool
    ) -> None:
        upy_dir = Path(path) / name
        if upy_dir.exists():
            if not force_generate:
                print(
                    f"{upy_dir} already exists. Please remove it manually if you want to recreate it or run the tool with '-f' option again."
                )
                sys.exit(1)
            else:
                shutil.rmtree(upy_dir)

        upy_dir.mkdir(parents=True)

        return upy_dir

    @staticmethod
    def find_file(filename, search_path):
        """
        Search for a file in the specified directory and its subdirectories using pathlib.

        :param filename: The name of the file to search for.
        :param search_path: The path of the directory to search in.
        :return: The full path to the file if found, otherwise None.
        """
        if Path.is_file(Path(filename)):
            return Path(filename)

        search_path = Path(search_path)
        for file_path in search_path.glob('**/' + filename):  # rglob performs a recursive search
            if file_path.name == filename:
                return file_path
        return None

    @staticmethod
    def append_unique_line(file_name : str, line_to_append : str) -> None:
        """
        Appends a string to the end of the specified file only if the same line
        does not already exist in the file.

        :param file_name: The name of the file to append to.
        :param line_to_append: The string to append to the file.
        """
        try:
            with open(file_name, 'r') as file:
                lines = file.readlines()

            # Check if the line already exists in the file
            if line_to_append + '\n' not in lines:
                with open(file_name, 'a') as file:
                    file.write(line_to_append + '\n')
        except FileNotFoundError:
            # If the file does not exist, create it and append the line
            with open(file_name, 'w') as file:
                file.write(line_to_append + '\n')

class src_generator:
    def __init__(self, fidl_name : str):
        self.fidl_data = fidl_file_info(fidl_name=fidl_name)
        self.gen_root_path = ""

    def set_gen_root(self, root_path : str) -> None:
        self.gen_root_path = root_path

    def gen_fdepl(self, platform_spec_path : str):
        template = """package org.endurosat.deploy

import "{{platform_spec_path}}"
import "{{fidl_trimmed_path}}"

define org.endurosat.spec.PlatformSpec for interface {{fidl_package_name}}.{{fidl_if_name}}            { IsClient = true }
"""
        data = {
            "fidl_if_name": self.fidl_data.fidl_if_name,
            "fidl_package_name": self.fidl_data.fidl_package_name,
            "fidl_trimmed_path": file_utils.convert_to_relative_path(
                self.gen_root_path, str(self.fidl_data.fidl_path.resolve())
            ).replace("\\", "/"),
            "platform_spec_path": file_utils.convert_to_relative_path(
                self.gen_root_path, platform_spec_path
            ).replace("\\", "/"),
        }

        j2_template = Template(template)

        return j2_template.render(data)

    def gen_cmake(self, fdepl_file_name : str) -> None:
        template = """#
# INTERFACE library for the {{fidl_if_name}} uPy FIDL API
#

set(libname usermod_{{fidl_if_name_lower}})

add_library(${libname} INTERFACE)

cmake_path(SET fdepl_path "${CMAKE_CURRENT_LIST_DIR}/{{fdepl_file_name}}")
cmake_path(SET fidl_path "${CMAKE_CURRENT_LIST_DIR}/{{fidl_trimmed_path}}")
cmake_path(SET c_mod_gen_root_path "${CMAKE_CURRENT_LIST_DIR}/src-gen-upy")
cmake_path(SET c_mod_gen_path "${c_mod_gen_root_path}/{{fidl_if_name}}/v{{fidl_version}}/gen")
cmake_path(SET upy_c_path "${CMAKE_CURRENT_LIST_DIR}/upy_{{fidl_if_name_lower}}.c")

list(APPEND src_dep_list
    ${upy_c_path}
)

# Add our source files to the lib
target_sources(${libname} INTERFACE
    ${upy_c_path}
)

# Add the current directory as an include directory
target_include_directories(${libname} INTERFACE
    "${CMAKE_CURRENT_LIST_DIR}"
)

set(gen_dependencies
    ${fdepl_path}
    ${fidl_path}
)

add_custom_command(
    OUTPUT ${upy_c_path}
    COMMAND ${MACARON_CMD} -pt=--gen-upy -dc=${fdepl_path} VERBATIM
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${c_mod_gen_path} ${CMAKE_CURRENT_LIST_DIR}
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_LIST_DIR}/../delete_folder.py ${c_mod_gen_root_path}
    DEPENDS ${gen_dependencies}
)

# Link our INTERFACE library to the usermod target.
target_link_libraries(usermod INTERFACE ${libname})

add_custom_target(gen-{{fidl_if_name_lower}}-upy DEPENDS ${upy_c_path})

add_dependencies(${libname} gen-{{fidl_if_name_lower}}-upy)
"""
        data = {
            "fidl_if_name": self.fidl_data.fidl_if_name,
            "fidl_if_name_lower":  self.fidl_data.fidl_if_name.lower(),
            "fidl_package_name": self.fidl_data.fidl_package_name,
            "fidl_version": self.fidl_data.fidl_version,
            "fdepl_file_name": Path(fdepl_file_name).name,
            "fidl_trimmed_path": file_utils.convert_to_relative_path(
                self.gen_root_path, str(self.fidl_data.fidl_path.resolve())
            ).replace("\\", "/"),
        }

        j2_template = Template(template)

        return j2_template.render(data)


def main():
    parser = argparse.ArgumentParser(description="A simple script to prepare the necessary CMake files to enable generation of a uPy binding from a FIDL file")
    parser.add_argument("--fidl", help="Path to a FIDL file for which to generate a uPy binding", required=True)
    parser.add_argument(
        "--fidl-root", help="Path to the FIDL root folder in the current SDK", required=True
    )
    parser.add_argument(
        "--usermod-cmake", help="Path to the usermod CMake file which includes all bindings and builds them. If specified, the newly generated binding will be added automatically to this file as an include."
    )
    parser.add_argument(
        "-f", "--force", action="store_true",
        help="Generate again even if the generated folder already exists. Using this option may result in loss of data if you have manually modified the generated files."
    )

    args = parser.parse_args()

    if (args.fidl) and (args.fidl_root):
        fidl_file_path = file_utils.find_file(args.fidl, str(Path(args.fidl_root).resolve()))

        platform_spec_fname : str = "PlatformSpec.fdepl"

        platform_spec_path = file_utils.find_file(
            platform_spec_fname, str(Path(args.fidl_root).resolve()))

        if fidl_file_path != None:
            print(f"=> FIDL file found in: '{fidl_file_path.resolve()}'")
        else:
            print(f"Could not find '{args.fidl}'. Please make sure the file exists!")
            sys.exit(1)

        if platform_spec_path != None:
            print(
                f"=> {platform_spec_fname} file found in: '{platform_spec_path.resolve()}'"
            )
        else:
            print(
                f"Could not find '{platform_spec_fname}'. Please make sure the file exists!"
            )
            sys.exit(1)

        src_gen = src_generator(fidl_file_path)
        upy_dir_path = file_utils.create_upy_dir(src_gen.fidl_data.fidl_if_name.lower(), str(Path.cwd().resolve()), args.force)
        src_gen.set_gen_root(upy_dir_path)

        fdepl_file_name = (
            Path(upy_dir_path) / f"{src_gen.fidl_data.fidl_if_name.lower()}_upy.fdepl"
        )

        print(f'\nGenerating CMake files for {args.fidl}...', end='')
        with open(f'{Path(upy_dir_path) / "micropython.cmake"}', "w+") as f:
            f.write(src_gen.gen_cmake(fdepl_file_name))

        with open(fdepl_file_name, "w+") as fdepl_f:
            fdepl_f.write(
                src_gen.gen_fdepl(str(platform_spec_path.resolve()))
            )

        print(f"[ok]\nYour files are here: '{upy_dir_path}'")

        if args.usermod_cmake:
            if Path.is_file(Path(args.usermod_cmake)):
                file_utils.append_unique_line(
                    str(Path(args.usermod_cmake).resolve()),
                    "include(${CMAKE_CURRENT_LIST_DIR}/" + src_gen.fidl_data.fidl_if_name.lower() + "/micropython.cmake)",
                )
                print(
                    f"Generated CMake file included in '{args.usermod_cmake}' successfully!"
                )
            else:
                print(f"Could not add the generated CMake include to '{args.usermod_cmake}' because the file doesn't exist. Please check the name again!")
                sys.exit(1)

        sys.exit(0)
    else:
        parser.print_help()
        sys.exit(1)

if __name__ == "__main__":
    main()
