#!/usr/bin/python3
"""[summary]
"""

import sys


def validate(args):
    """[summary]

    Args:
        args ([type]): [description]

    Returns:
        [type]: [description]
    """
    if len(args) > 2:
        print("Usage: nqueens N")
        exit(1)
    else:

        try:
            number = int(args[1])
            if number < 4:
                print("N must be at least 4")
                exit(1)
        except Exception:
            print("N must be a number")
            exit(1)

        return number


def solveNQ(number):
    """[summary]

    Args:
        number ([type]): [description]

    Returns:
        [type]: [description]
    """
    board = []
    for i in range(number):
        numbers = []
        for j in range(number):
            numbers.append(0)
        board.append(numbers)

    if not solveNQUtil(board, 0, number):
        return False

    return True


def solveNQUtil(board, col, number):
    """[summary]

    Args:
        board ([type]): [description]
        number ([type]): [description]
        col ([type]): [description]

    Returns:
        [type]: [description]
    """
    if (col == number):
        print_board(board)
        return True
    answer = False

    for i in range(number):
        if (isSafe(board, i, col, number)):
            board[i][col] = 1
            answer = solveNQUtil(board, col + 1, number) or answer
            board[i][col] = 0

    return answer


def isSafe(board, row, col, number):
    """[summary]

    Args:
        board ([type]): [description]
        row ([type]): [description]
        col ([type]): [description]
        number ([type]): [description]

    Returns:
        [type]: [description]
    """
    for i in range(col):
        if board[row][i] == 1:
            return False

    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    for i, j in zip(range(row, number, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True


def print_board(board):
    """[summary]

    Args:
        board ([type]): [description]
    """
    new_board = []
    for i, row in enumerate(board):
        value = []
        for j, col in enumerate(row):
            if col == 1:
                value.append(i)
                value.append(j)
        new_board.append(value)

    print(new_board)

if __name__ == "__main__":
    number = validate(sys.argv)
    solveNQ(number)
