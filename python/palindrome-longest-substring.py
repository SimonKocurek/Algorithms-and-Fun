# Given a string, find the longest palindromic contiguous substring.
# If there are more than one with the maximum length, return any one.
#
# For example, the longest palindromic substring of "aabcdcb" is "bcdcb".
# The longest palindromic substring of "bananas" is "anana".


def spread(start, end, string):
    while start - 1 >= 0 and end + 1 < len(string) and string[start - 1] == string[end + 1]:
        start -= 1
        end += 1

    return start, end


def longest_substring(string):
    longest = ''

    for i in range(len(string)):
        start, end = spread(i, i, string)
        if end - start + 1 > len(longest):
            longest = string[start:end + 1]

    for i in range(len(string) - 1):
        if string[i] != string[i + 1]:
            continue

        start, end = spread(i, i + 1, string)
        if end - start + 1 > len(longest):
            longest = string[start:end + 1]

    return longest


print(longest_substring('aabcdcb'), 'expected', 'bcdcb')
print(longest_substring('bananas'), 'expected', 'anana')
print(longest_substring('aaaa'), 'expected', 'aaaa')
print(longest_substring(''), 'expected', '')
print(longest_substring('abcdd'), 'expected', 'dd')
