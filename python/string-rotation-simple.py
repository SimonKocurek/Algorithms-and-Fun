def is_substring(a, b):
    return a in b


def is_rotation(a, b):
    if len(a) != len(b):
        return False
    
    return is_substring(b, a + a)

a = input()
b = input()
print(is_rotation(a, b))

