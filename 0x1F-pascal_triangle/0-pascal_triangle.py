#!/usr/bin/python3
"""function that returns a list of lists
of integers representing the Pascal’s triangle of n"""


def pascal_triangle(n):
    """pascal triangle"""
    if n <= 0:
        return []

    triangle = []
    nodo = 1
    for fila in range(n):
        triangle.append(nodo)
        if fila >= 2:
            copylist = []
            copylist.insert(0, nodo)
            index = 1
            count = 0
            while index < fila:
                copylist.insert(index, (triangle[count] + triangle[index]))
                index += 1
                count += 1

            copylist.insert(fila, triangle[fila])
            triangle.clear()
            triangle.extend(copylist)
            copylist.clear()
    return triangle
