#!/usr/bin/python3

""" Given a list of non-negative integers representing walls of width 1,
    calculate how much water will be retained after it rains.
"""


def rain(walls):
    """ Calculates how many units of water is caught
        by walls 1 unit wide on a 2-d plane
    """
    water_amt = 0

    # Traverse rain list
    for i in range(1, len(walls) - 1):

        # Find max element on left
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        # Find max element on right
        right = walls[i]
        for j in range(i + 1, len(walls)):
            right = max(right, walls[j])

        water_amt += (min(left, right) - walls[i])

    return water_amt
