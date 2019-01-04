# 1 2 3
# 4 5 6
# 7 8 9
#   0

NEIGHBOURS = {
    1 : (6, 8),
    2 : (7, 9),
    3 : (8, 4),
    4 : (3, 0),
    5 : tuple(),
    6 : (1, 7, 0),
    7 : (2, 6),
    8 : (1, 3),
    9 : (2, 4),
    0 : (4, 6)
}

def dialable_numbers(digit_count, current_number, cache={}):
    if digit_count <= 1:
        return max(digit_count, 0)

    if digit_count == 2:
        return len(NEIGHBOURS[current_number])

    if (digit_count, current_number) in cache:
        return cache[(digit_count, current_number)]

    result = 0

    for neighbour in NEIGHBOURS[current_number]:
        result += dialable_numbers(digit_count - 1, neighbour)

    cache[(digit_count, current_number)] = result
    return result

print(dialable_numbers(-1, 3))
print(dialable_numbers(0, 3))
print(dialable_numbers(1, 3))
print(dialable_numbers(2, 3))
print(dialable_numbers(10, 6))
print(dialable_numbers(20, 5))
