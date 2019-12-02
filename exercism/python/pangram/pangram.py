from string import ascii_lowercase

def is_pangram(sentence):
    found = [char for char in ascii_lowercase if char in sentence.lower()]
    return len(found) == 26
