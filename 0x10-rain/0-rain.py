#!/usr/bin/python3
"""rain module
"""


def rain(walls):
    """calculate how many square units of water will be
    retained after it rains
    """
    result = 0

    for i in range(1, len(walls) - 1):
        left_wall = walls[i]
        for j in range(i):
            left_wall = max(left_wall, walls[j])
        right_wall = walls[i]
        for j in range(i + 1, len(walls)):
            right_wall = max(right_wall, walls[j])

        result = result + (min(left_wall, right_wall) - walls[i])

    return result
