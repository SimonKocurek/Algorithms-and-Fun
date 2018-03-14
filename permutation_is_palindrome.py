def can_be_palindrome(s):
    s = s.replace(' ', '')
    s = s.lower()

    char_odd = 0
    for char in s:
        char_odd ^= 1 << (ord(char) - ord('a')) 
    
    can_be_odd = True
    for i in range(27):
        if char_odd & (1 << i) > 0:
            if can_be_odd:
                can_be_odd = False
            else:
                return False

    return True

s = input()
print(can_be_palindrome(s))

