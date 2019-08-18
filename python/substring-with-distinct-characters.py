from collections import defaultdict


def length_of_substring_with_at_most_k_distinct_characters(string: str, k: int) -> int:
    if k <= 0:
        return 0

    result = 0

    start = 0
    seen = defaultdict(int)
    for i, letter in enumerate(string):
        seen[letter] += 1

        while len(seen) > k:
            removed = string[start]
            seen[removed] -= 1

            if seen[removed] == 0:
                del seen[removed]

            start += 1

        result = max(result, i - start + 1)

    return result


def main() -> None:
    print(length_of_substring_with_at_most_k_distinct_characters('', 0), 'Expected: 0')
    print(length_of_substring_with_at_most_k_distinct_characters('1', 0), 'Expected: 0')
    print(length_of_substring_with_at_most_k_distinct_characters('ab', 0), 'Expected: 0')
    print(length_of_substring_with_at_most_k_distinct_characters('aba', 0), 'Expected: 0')
    print(length_of_substring_with_at_most_k_distinct_characters('abaa', 0), 'Expected: 0')
    print(length_of_substring_with_at_most_k_distinct_characters('eceba', 0), 'Expected: 0')
    print(length_of_substring_with_at_most_k_distinct_characters('ecebeeeaab', 0), 'Expected: 0')

    print(length_of_substring_with_at_most_k_distinct_characters('', 1), 'Expected: 0')
    print(length_of_substring_with_at_most_k_distinct_characters('1', 1), 'Expected: 1')
    print(length_of_substring_with_at_most_k_distinct_characters('ab', 1), 'Expected: 1')
    print(length_of_substring_with_at_most_k_distinct_characters('aba', 1), 'Expected: 1')
    print(length_of_substring_with_at_most_k_distinct_characters('abaa', 1), 'Expected: 2')
    print(length_of_substring_with_at_most_k_distinct_characters('eceba', 1), 'Expected: 1')
    print(length_of_substring_with_at_most_k_distinct_characters('ecebeeeaab', 1), 'Expected: 3')

    print(length_of_substring_with_at_most_k_distinct_characters('', 2), 'Expected: 0')
    print(length_of_substring_with_at_most_k_distinct_characters('1', 2), 'Expected: 1')
    print(length_of_substring_with_at_most_k_distinct_characters('ab', 2), 'Expected: 2')
    print(length_of_substring_with_at_most_k_distinct_characters('aba', 2), 'Expected: 3')
    print(length_of_substring_with_at_most_k_distinct_characters('abaa', 2), 'Expected: 4')
    print(length_of_substring_with_at_most_k_distinct_characters('eceba', 2), 'Expected: 3')
    print(length_of_substring_with_at_most_k_distinct_characters('ecebeeeaab', 2), 'Expected: 5')

    print(length_of_substring_with_at_most_k_distinct_characters('', 3), 'Expected: 0')
    print(length_of_substring_with_at_most_k_distinct_characters('1', 3), 'Expected: 1')
    print(length_of_substring_with_at_most_k_distinct_characters('ab', 3), 'Expected: 2')
    print(length_of_substring_with_at_most_k_distinct_characters('aba', 3), 'Expected: 3')
    print(length_of_substring_with_at_most_k_distinct_characters('abaa', 3), 'Expected: 4')
    print(length_of_substring_with_at_most_k_distinct_characters('eceba', 3), 'Expected: 4')
    print(length_of_substring_with_at_most_k_distinct_characters('ecebeeeaab', 3), 'Expected: 8')


if __name__ == '__main__':
    main()
