import argparse
import re

def find_method_names(filename):
    with open(filename, 'r', encoding='utf-8', errors='replace') as file:
        content = file.read()
        
    # Look for patterns like " def <method_name>"
    method_pattern = re.compile(r'\s*method\s+(\w+)\s*')
    method_names = method_pattern.findall(content)
    
    return method_names

def main():
    parser = argparse.ArgumentParser(description='Parse a FIDL file and generate a deployment schema selection block to paste into your fdepl file')
    parser.add_argument('filename', type=str, help='The path to the FIDL file to parse.')

    args = parser.parse_args()

    method_names = find_method_names(args.filename)
    
    for method_name in method_names:
        print(f"method {method_name} {{ InUse = false }}")

if __name__ == '__main__':
    main()
