#!/usr/bin/python3

'''
Determines if a given data set represents a valid UTF-8 encoding.
'''


def validUTF8(data):
    num_bytes = 0

    # Least significant 8 bits
    for number in data:
        binary_rep = format(number, '#010b')[-8:]

    # If valid
    if num_bytes == 0:
        # How many 1s at beginning
        for bit in binary_rep:
            if bit == '0':
                break
            num_bytes += 1

            if num_bytes == 0:
                continue

            # invalid
            if num_bytes == 1 or num_bytes > 4:
                return False
            else:
                if not (binary_rep[0] == '1' and binary_rep[1] == '0'):
                    return False

            num_bytes -= 1

    return num_bytes == 0
