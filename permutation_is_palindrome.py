def can_be_palindrome(s):
    s = s.replace(' ', '')
    s = s.lower()

    char_odd = 0
    for char in s:
        char_odd ^= 1 << (ord(char) - ord('a')) 
    
    char_odd_ones = char_odd - 1
    return char_odd & char_odd_ones == 0

s = input()
print(can_be_palindrome(s))

