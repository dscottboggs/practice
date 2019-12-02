"""
Example Input
    7 11
    5 15
    3 2
    -2 2 1
    5 -6
Example output
    1
    1
"""
import sys, os
def countApplesAndOranges(s, t, a, b, apples, oranges):
    #
    # Write your code here.
    #
    applesHit, orangesHit = 0,0
    for apple in apples:
        if t>=(a+apple)>=s:
            applesHit+=1
    for orange in oranges:
        if t>=(b+orange)>=s:
            orangesHit+=1
    print(f"{ applesHit }\n{ orangesHit }")

if __name__ == '__main__':
    st = input().split()

    s = int(st[0])

    t = int(st[1])

    ab = input().split()

    a = int(ab[0])

    b = int(ab[1])

    mn = input().split()

    m = int(mn[0])

    n = int(mn[1])

    apple = list(map(int, input().rstrip().split()))

    orange = list(map(int, input().rstrip().split()))

    countApplesAndOranges(s, t, a, b, apple, orange)
