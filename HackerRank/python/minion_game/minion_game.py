VOWELS = ['A', 'E', 'I', 'O', 'U']


def minion_game(string):
    # your code goes here
    unique_substrings = set(all_substrings(string))
    de_stuart = set([s for s in unique_substrings if s[0] not in VOWELS])
    de_kevin = set([s for s in unique_substrings if s[0] in VOWELS])
    stuart = count_in(de_stuart, string)
    kevin = count_in(de_kevin, string)
    print(
        "Stuart %d" % (stuart+1) if stuart > kevin else "Kevin %d" % (kevin+1)
    )


def count_in(substrings, string):
    count = 0
    for s in substrings:
        count += string.count(s)
    return count


def all_substrings(string):
    out = []
    for number_of_letters in range(1, len(string)):
        index = 0
        for index in range(len(string)):
            out.append(string[index:index+number_of_letters])
    return out


if __name__ == '__main__':
    s = input()
    minion_game(s)
