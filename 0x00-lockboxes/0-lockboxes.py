#!/usr/bin/python3
"""
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and
each box may contain keys to the other boxes.
"""


def canUnlockAll(boxes):
    """
    method that determines if all the boxes can be opened.
    boxes is a list of lists
    A key with the same number as a box opens that box
    The first box boxes[0] is unlocked
    Return True if all boxes can be opened, else return False
    """
    myList = [0]
    for key in myList:
        for boxeKey in boxes[key]:
            if boxeKey not in myList and boxeKey < len(boxes):
                myList.append(boxeKey)
    if len(myList) == len(boxes):
        return True
    return False
