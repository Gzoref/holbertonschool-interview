#!/usr/bin/python3

import sys

'''
Reads stdin line by line and computes metrics
'''
status = {'200': 0, '301': 0, '400': 0, '401': 0,
          '403': 0, '404': 0, '405': 0, '500': 0}
codes = ['200', '301', '400', '401', '403', '404', '405', '500']

count = 0
file_size = 0

try:
    for line in sys.stdin:
        count += 1
        result = line.split(' ')
        if len(result) > 2:
            file_size += int(result[-1])
            if result[-2] in status:
                status[result[-2]] += 1
        if count % 10 == 0:
            print("File size: {}".format(file_size))
            for code in codes:
                if status[code]:
                    print("{}: {}".format(code, status[code]))
except KeyboardInterrupt:
    pass
finally:
    print("File size: {}".format(file_size))
    for code in codes:
        if status[code]:
            print("{}: {}".format(code, status[code]))
