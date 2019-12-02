"""HackerRank staircase algorithm problem."""
from sys import argv


def get_input() -> int:
    """Check for an input value on stdin, otherwise prompt for one."""
    if len(argv) == 1:
        # get input if it wasn't in the args
        return int(input("Number of rows/columns in staircase: "))
    # or the first input from argv, ignoring anything else.
    return int(argv[1])


def get_staircase(n):
    """Loop through each row and column, printing the appropriate character."""
    for row in range(n):
        # iterating over each row
        for col in range(n):
            # and each column
            print(" " if col < n-row-1 else "#", end='')
            # The hash symbol should be printed in the case we're on the right-
            # hand n-row-1 (the total width minus the current level of height,
            # minus the hash symbol that will be displayed at the end of this
            # row), we print a hash symbol. If we're on the left-hand n-row-1,
            # we print a space to get the hash symbols bumped over to the
            # right.
        print('')


get_staircase(get_input())
