def is_unique(s):
    if len(s) > 256:
        return False

    chars = [False] * 256
    for c in s:
        if chars[ord(c)]:
            return False
        chars[ord(c)] = True

    return True

s = input()
print(is_unique(s))

