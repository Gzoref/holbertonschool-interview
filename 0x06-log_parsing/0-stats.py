#!/usr/bin/python3


'''
Reads stdin line by line and computes metrics
'''
import sys

status_code = {
    '200': 0, '301': 0, '400': 0, '401': 0,
    '403': 0, '404': 0, '405': 0, '500': 0
}

file_size = 0
count = 0


def print_log():
    '''
    Print log stats
    '''
    print('File size: ' + str(file_size))
    for line in status_code:
        if status_code[line] != 0:
            print(line + ': ' + str(status_code[line]))


try:
    for line in sys.stdin:
        result = line.split()
        if len(result) > 2:
            file_size += result[-1]
            status_code[int(result[-2])] += 1
            count += 1
        if count == 10:
            print_log()
            count = 0
            else:
                count += 1
except KeyboardInterrupt:
    print_log()
