
def bishop_attacks(bishops):
    result = 0

    for i in range(len(bishops)):
        for j in range(i + 1, len(bishops)):
            x, y = bishops[i]
            x2, y2 = bishops[j]

            if abs(x - x2) == abs(y - y2):
                result += 1

    return result

print(bishop_attacks([(0, 0), (1, 2), (2, 2), (4, 0)]))
