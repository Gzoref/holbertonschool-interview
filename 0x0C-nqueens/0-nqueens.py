#!/usr/bin/python3

'''
N queens
'''

import sys

if len(sys.argv) != 2:
    print('Usage: nqueens N')
    exit(1)

try:
    N = sys.argv[1]
except BaseException:
    print('N must be a number')
    exit(1)

if N < 4:
    print('N must be at least 4')
