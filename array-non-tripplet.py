# Given an array of integers where every integer
# occurs three times except for one integer, 
# which only occurs once, find and return the 
# non-duplicated integer.
#
# For example, given [6, 1, 3, 3, 3, 6, 6], return 1.
# Given [13, 19, 13, 13], return 19.
#
# Do this in O(N) time and O(1) space.

def once(numbers):
    bits = [0] * 32

    for number in numbers:
        for bit in range(32):
            if number & (1 << bit):
                bits[bit] += 1

    result = 0
    for bit in range(32):
        if bits[bit] % 3 == 1:
            result |= 1 << bit

    return result

print(once([6, 1, 3, 3, 3, 6, 6]))        
print(once([13, 19, 13, 13]))        
print(once([2]))        
