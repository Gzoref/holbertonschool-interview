#!/usr/bin/python3

import sys

'''
Reads stdin line by line and computes metrics
like file size
'''

if __name__ == "__main__":

    status_codes = {200: 0, 301: 0,
                    400: 0, 401: 0,
                    403: 0, 404: 0,
                    405: 0, 500: 0}

    file_size = [0]

    def check_wordmatch(line):
        try:
            line = line[:-1]
            words = line.split(" ")
            file_size[0] += int(words[-1])
            code = int(words[-2])
            if code in status_codes:
                status_codes[code] += 1
        except BaseException:
            pass

    def print_metric():
        print("File size: {}".format(file_size[0]))
        for k in sorted(status_codes.keys()):
            if status_codes[k]:
                print("{}: {}".format(k, status_codes[k]))

    count = 1
    try:
        for line in sys.stdin:
            check_wordmatch(line)
            if count % 10 == 0:
                print_metric()
            count += 1
    except KeyboardInterrupt:
        print_metric()
        raise
    print_metric()
