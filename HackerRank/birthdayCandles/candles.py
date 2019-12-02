#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the birthdayCakeCandles function below.
# def birthdayCakeCandles(ar):
#     tallest = 0
#     for candle in ar:
#         if candle > tallest:
#             tallest = candle
#     return ar.count(tallest)

def birthdayCakeCandles(ar):
    return sorted(ar)[-1]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    ar_count = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = birthdayCakeCandles(ar)

    fptr.write(str(result) + '\n')

    fptr.close()
