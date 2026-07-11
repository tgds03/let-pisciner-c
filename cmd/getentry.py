#!/bin/python3
import sys, os
from pycparser import parse_file
from pycparser.c_parser import ParseError, CParser

def find_entry_file(filename: str):
    shell_path = os.getenv("SHELL_PATH")
    include_path = os.getenv("INCLUDE_PATH")
    include_std_path = shell_path + "/.venv/lib/python3.13/site-packages/pycparser/utils/fake_libc_include"
    misc_args=["-Wall", "-Wextra", "-Werror"]
    args = [f"-I{include_path}", f"-I{include_std_path}"] + misc_args
    try:
        ast = parse_file(filename, use_cpp=True, cpp_path="gcc", cpp_args=args)
    except ParseError as e:
        print(f"ParseError:{e}", file=sys.stderr)
        exit(1)
    
    ast.show(showcoord=True)

def find_entry_stdin():
    code = sys.stdin.read()
    parser = CParser()
    try:
        ast = parser.parse(code)
    except ParseError as e:
        print(f"ParseError:{e}", file=sys.stderr)
        exit(1)
    
    ast.show(showcoord=True)

if __name__=='__main__':
    find_entry_stdin()