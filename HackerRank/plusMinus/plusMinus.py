#!/bin/python3


def getInput():
    int(input().strip())
    inputStr  = input().strip()
    return [int(s) for s in inputStr.split()]


def main():
    POS = NEG = ZERO = 0
    for number in getInput():
        if number > 0:
            POS += 1
        elif number == 0:
            ZERO += 1
        else:
            NEG += 1
    print(POS, NEG, ZERO)


if __name__ == '__main__':
    main()
