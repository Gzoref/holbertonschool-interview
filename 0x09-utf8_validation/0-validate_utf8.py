#!/usr/bin/python3

'''
Determines if a given data set represents a valid UTF-8 encoding.
'''

def validUTF8(data):
	return 



'''
Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

 0   0  0  0  0  0  0  0
128  64 32 16 8  4  2  1

< 128 
01100001 65 A

> 128

2 bytes:

1 1 0 x x x x x  1 0 x x x x x x 
      0 0 1 1 0      1 1 0 0 1 0
			\           /
	    0 0 1 1 0 1 1 0 0 1 0

3 bytes:
1 1 1 x x x x x  1 0 0 x x x x x  1 0 0 x x x x x
          \              |             /
	   0 0 1 0 0		0 0 0 0 1       0 1 0 1 0
	        \             |                /
			 0 0 1 0 0 0  0 0 0 1 0 1 0 1 0
'''