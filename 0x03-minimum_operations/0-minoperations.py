#!/usr/bin/python3

'''
Given a number n, write a method that calculates
the fewest number of operations needed to result in
exactly n H characters in the file.
'''


def minOperations(n):
    '''
    returns min operations to get n Hs
    '''
    result = 0
    if type(n) is not int or n < 2:
        return 0
    for i in range(2, n):
        # Check if problem is evenly brekadownable
        while n % i == 0:
            # If so add number of smaller problems to the result
            result += i
            # Create the smaller problem needed to get to n
            n /= i
    return result
