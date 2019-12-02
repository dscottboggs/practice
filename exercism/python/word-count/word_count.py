from re import findall
def count_words(sentence):
    word_counts = {}
    for word in findall(r"\w*'?\w", sentence):
        word_counts[word] = word_counts.get(word, 0) + 1
    return word_counts
