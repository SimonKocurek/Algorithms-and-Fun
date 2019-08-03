def is_permutation(s1, s2):
    return sorted(s1) == sorted(s2)

s1, s2 = input(), input()
print(is_permutation(s1, s2))

