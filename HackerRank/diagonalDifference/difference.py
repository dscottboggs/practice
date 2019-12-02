from typing import List
"""The absolute value of the difference between the diagonals of a 2D array.

input should be:
Width/Height of the array on the first input line
any subsequent line should contain the space-separated values.
"""


def right_diagonal_sum(arrays: List[List[int]]) -> int:
    """Sum the right diagonal of the given 2d array."""
    outsum = 0
    for index in range(len(arrays)):
        outsum += arrays[index][index]
    return outsum


def left_diagonal_sum(arrays: List[List[int]]) -> int:
    """Sum the left diagonal of the given 2d array."""
    outsum = 0
    row = 0
    column = len(arrays) - 1
    while row < len(arrays):
        outsum += arrays[row][column]
        column -= 1
        row    += 1
    return outsum


def diagonal_difference(arrays: List[List[int]]) -> int:
    """Get the absolute value of the difference between the diagonals.

    @param arrays:  must be a sqare matrix - i.e. an array of arrays where the
                    number of arrays is the same as the number of values in
                    each array.
    """
    return abs(right_diagonal_sum(arrays) - left_diagonal_sum(arrays))


def main():
    rows = int(input("Number of arrays to be specified."))
    a = [
        int(element) for element in [
            input(f"Array #{row}: ").split(' ') for row in range(rows)
        ]
    ]
    print(diagonal_difference(a))
