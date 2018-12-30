def get_letter_positions(word):
    letter_positions = {}

    for i in range(len(word)):
        char = word[i]
        if char not in letter_positions:
            letter_positions[char] = []

        letter_positions[char].append(i)

    return letter_positions

def is_subsequence_of(letter_positions, word):
    pointer = 0

    for letter in word:
        if letter not in letter_positions:
            return False

        for point in letter_positions[letter]:
            if pointer <= point:
                pointer = point
                break
        else:
            return False

    return True


def longest_subsequence(word, dictionary):
    letter_positions = get_letter_positions(word)

    result = ''
    for word in dictionary:
        if is_subsequence_of(letter_positions, word) and len(result) < len(word):
            result = word

    return result if len(result) > 0 else None

print(longest_subsequence('abppple', ['able', 'ale', 'apple', 'bale', 'kangaroo']))
