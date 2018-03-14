def can_be_palindrome(s):
    s = s.replace(' ', '')
    s = s.lower()

    char_count = [0] * 256
    for char in s:
        char_count[ord(char)] += 1
    
    can_be_odd = len(s) % 2 == 1
    for count in char_count:
        if count % 2 == 1:
            if can_be_odd:
                can_be_odd = False
            else:
                return False

    return True

s = input()
print(can_be_palindrome(s))

