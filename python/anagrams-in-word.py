from collections import Counter

def anagram_count(word: str, searched: str) -> int:
    if len(searched) > len(word):
        return 0

    result = 0

    required = Counter(searched)
    for i in range(len(word)):
        letter = word[i]
        required[letter] -= 1
        if required[letter] == 0:
            del required[letter]

        if i < len(searched):
            if i + 1 == len(searched) and len(required) == 0:
                result += 1
            continue

        removed = word[i - len(searched)]
        required[removed] += 1
        if required[removed] == 0:
            del required[removed]

        if len(required) == 0:
            result += 1

    return result

def main():
    print(anagram_count('forxxorfxdofr', 'for'), 'Expected 3')
    print(anagram_count('aabaabaa', 'aaba'), 'Expected 4')

if __name__ == "__main__":
    main()
