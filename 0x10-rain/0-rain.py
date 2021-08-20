#!/usr/bin/python3
"""rain module
"""


def rain(walls):
    """calculate how many square units of water will be
    retained after it rains
    """
    if walls is None:
        return 0
    left_wall = 0
    right_wall = 0
    result = 0
    index = walls.index(0)
    if index == walls[0]:
        i = 1
        while i <= len(walls) - 1:
            if walls[i] == 0:
                left_wall = walls[i - 1]
                right_wall = walls[i + 1]
            if left_wall < right_wall:
                result += left_wall
                left_wall = 0
                right_wall = 0
            i += 1
        return result
    else:
        count = 0
        auxiliary = 0
        i = 0
        left_wall = walls[i]
        while i <= len(walls) - 2:
            if walls[i] == 0:
                count += 1
                right_wall = walls[i + 1]
            else:
                count = 0
            if left_wall < right_wall:
                auxiliary = left_wall * count
                result += auxiliary
                count = 0
                left_wall = right_wall
            else:
                auxiliary = right_wall * count
                result += auxiliary
            i += 1
        return result
