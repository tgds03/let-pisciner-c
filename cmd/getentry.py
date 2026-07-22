#!/bin/python3
import sys, os, re
from pycparser import parse_file
from pycparser.c_parser import ParseError, CParser
from pycparser.c_ast import FuncDef

def preprocess(code: str):
	return re.sub(r"__attribute__\(\(\w+\)\)", "", code)

def find_entry_stdin():
    code = sys.stdin.read()
    code = preprocess(code)
    parser = CParser()
    try:
        ast = parser.parse(code)
    except ParseError as e:
        print(f"ParseError:{e}", file=sys.stderr)
        exit(1)

    for item in reversed(ast.ext):
        if (isinstance(item, FuncDef) and item.decl.name == 'main'):
            item.show(showcoord=True)

if __name__=='__main__':
    find_entry_stdin()
