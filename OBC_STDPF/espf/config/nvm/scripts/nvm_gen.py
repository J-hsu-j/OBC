import re
import sys
import shutil
from pathlib import Path

# Define a global filter list and a list of input files to parse enums from
filter_list = ["NVM_BOOT_BLOCK_MAX_COUNT", "MAX_COUNT"]

def is_negative_match(string):
    """
    Determine if the given string is a negative match based on specific criteria.

    Criteria for a negative match:
    - The string starts with a C-style comment (either '/*' or '//').
    - The string starts with a '#' symbol indicating a preprocessor line.

    :param string: The string to evaluate.
    :return: True if the string is a negative match; False otherwise.
    """
    # Trim leading whitespace
    stripped_string = string.lstrip()

    # Check for C-style comments and preprocessor line
    if stripped_string.startswith(('/*', '//', '#')):
        return True
    return False

def parse_enum_literals_from_file(file_content):
    """Parse enum literals from given file content."""
    enum_literals = []
    pattern = r"^\s*([A-Z_\d]+)\s*(?:=\s*[A-Z_0-9]+)?,?\s*$"

    in_enum_block = False

    for line in file_content.splitlines():
        if 'enum' in line:
            in_enum_block = True
            continue

        if in_enum_block:
            if '}' in line:  # End of enum block
                break
            if is_negative_match(line):  # Skip preprocessor lines
                continue

            match = re.match(pattern, line)
            if match:
                full_literal = match.group(1)
                if full_literal.startswith("NVM_BLOCK_"):
                    literal = full_literal[len("NVM_BLOCK_"):]
                else:
                    literal = full_literal
                if literal not in filter_list:
                    enum_literals.append(f'{" " * 8}{literal}')

    return enum_literals

def main():
    if len(sys.argv) != 6:
        print("Usage: script.py <input_file> <new_file> <boot blocks header path> <app blocks header path> <marker>")
        return

    input_file_path = sys.argv[1]
    new_file_path = sys.argv[2]
    file_list = [sys.argv[3], sys.argv[4]]
    marker = sys.argv[5]
    all_literals = []

    # Parse literals from each file
    for file_path in file_list:
        try:
            with open(file_path, 'r') as file:
                file_content = file.read()
                literals = parse_enum_literals_from_file(file_content)
                all_literals.extend(literals)
        except FileNotFoundError:
            print(f"File {file_path} not found.")
            continue

    # Make a copy of the input file to the new file path
    try:
        shutil.copy(input_file_path, new_file_path)
    except FileNotFoundError:
        print(f"Input file {input_file_path} not found.")
        return
    except Exception as e:
        print(f"An error occurred while copying the file: {e}")
        return

    # Read the new file and replace the marker
    try:
        with open(new_file_path, 'r') as file:
            content = file.read()

        # Replace the marker with the parsed literals
        literals_text = "\n".join(all_literals)
        new_content = content.replace(marker, literals_text)

        # Write the updated content back to the new file
        with open(new_file_path, 'w') as file:
            file.write(new_content)

    except Exception as e:
        print(f"An error occurred: {e}")

    print(f'"{Path(new_file_path).resolve()}" generated!')

if __name__ == "__main__":
    main()