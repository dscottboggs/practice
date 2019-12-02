import string
original_alphabet = string.ascii_lowercase


def fix_shift(val: int) -> int:
    while val >= len(original_alphabet):
        val -= len(original_alphabet)
    while val < 0:
        val += len(original_alphabet)
    return val


def convert_alphabet(shift: int):
    a1 = original_alphabet[:0-shift]
    a2 = original_alphabet[0-shift:]
    return a2 + a1


def encode(message: str, shift: int) -> str:
    alphabet = [ letter for letter in convert_alphabet(int(shift))]
    msgout = ''
    for letter in message:
        try:
            idx = original_alphabet.index(letter.lower())
            msgout += alphabet[idx] if letter.islower()\
                                   else alphabet[idx].upper()
        except ValueError:
            msgout += letter
    return msgout


def main():
    _, msg, shift = map(input, range(3))
    print(encode(msg, 0-shift))

if __name__ == '__main__':
    main()
