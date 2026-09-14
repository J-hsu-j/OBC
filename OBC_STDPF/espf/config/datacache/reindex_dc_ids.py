import sys
import re

def update_ids(file_path):
    try:
        with open(file_path, 'r') as file:
            lines = file.readlines()
        
        # Find all occurrences of the pattern and replace them with sequential numbers starting from 1
        id_count = 1
        pattern = re.compile(r'(@details:\s*id\s*=\s*0x)([0-9A-Fa-f]+)')
        
        new_lines = []
        for line in lines:
            new_line = line
            matches = pattern.findall(line)
            for match in matches:
                hex_id = f'{id_count:08X}'
                old_pattern = f'{match[0]}{match[1]}'
                new_pattern = f'{match[0]}{hex_id}'
                new_line = new_line.replace(old_pattern, new_pattern, 1)
                id_count += 1
            new_lines.append(new_line)
        
        # Write the modified content back to the file
        with open(file_path, 'w') as file:
            file.writelines(new_lines)
        
        print("File updated successfully.")
    
    except FileNotFoundError:
        print(f"Error: The file '{file_path}' does not exist.")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: python ", sys.argv[0]," <file_path>")
    else:
        file_path = sys.argv[1]
        update_ids(file_path)