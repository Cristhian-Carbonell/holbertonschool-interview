#!/usr/bin/python3
"""script that reads stdin line by line and computes metrics:"""
import sys

lines = sys.stdin
count = 1
size = []
code = {"200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0}

for line in lines:
    if count == 10:
        total_size = sum(size)
        print("File size: {}".format(total_size))
        size.clear()
        size.append(total_size)
        for i in code:
            if code[i] != 0:
                print("{}: {}".format(i, code[i]))
        count = 0

    str_line = line[-8:]
    size.append(int(str_line[4:]))
    str_code = str_line[:3]
    if str_code in code:
        code[str_code] += 1
    count += 1
