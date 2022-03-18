#!/usr/bin/python3
"""function that returns a list of lists
of integers representing the Pascal’s triangle of n"""


def pascal_triangle(n):
    """pascal triangle"""
    if n <= 0:
        return []
    lists = []
    triangle = []
    nodo = 1
    for row in range(n):
        lists.append([])
        if row < 2:
            triangle.append(nodo)
            lists[row].extend(triangle)
        else:
            copylist = []
            copylist.insert(0, nodo)
            index = 1
            count = 0
            while index < row:
                copylist.insert(index, (triangle[count] + triangle[index]))
                index += 1
                count += 1

            copylist.insert(row, nodo)
            triangle.clear()
            triangle.extend(copylist)
            lists[row].extend(triangle)
            copylist.clear()

    return lists
