# Given a string s and an integer k, break up the string into multiple texts such that each
# text has a length of k or less. You must break it up so that words don't break across lines.
# If there's no way to break the text up, then return null.
#
# You can assume that there are no spaces at the ends of the string and that there is exactly
# one space between each word.
#
# For example, given the string "the quick brown fox jumps over the lazy dog" and k = 10, you
# should return: ["the quick", "brown fox", "jumps over", "the lazy", "dog"]. No string in the
# list has a length of more than 10.


def split(string, line_length):
    result = []
    words = string.split()

    added = ''
    i = 0
    while i < len(words):
        if len(words[i]) > line_length:
            return None

        elif len(added) == 0:
            added = words[i]
            i += 1

        elif len(added) + 1 + len(words[i]) <= line_length:
            added += ' ' + words[i]
            i += 1

        else:
            result.append(added)
            added = ''

    if len(added) > 0:
        result.append(added)

    return result


print(split('the quick brown fox jumps over the lazy dog', 10))
