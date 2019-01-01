def found(word, matrix, y, x):
    directions = ((0, 1), (1, 0))

    for x_mov, y_mov in directions:
        for i in range(len(word)):
            x_new, y_new = x + x_mov * i, y+ y_mov * i
            if y_new >= len(matrix) or x_new >= len(matrix[y_new]) or word[i] != matrix[y_new][x_new]:
                break

        else:
            return True

    return False

def word_in_matrix(word, matrix):
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            if found(word, matrix, i, j):
                return True

    return False

matrix = [['F', 'A', 'C', 'I'],
 ['O', 'B', 'Q', 'P'],
 ['A', 'N', 'O', 'B'],
 ['M', 'A', 'S', 'S']]

print(word_in_matrix('FOAM', matrix))
print(word_in_matrix('MASS', matrix))
print(word_in_matrix('NOB', matrix))
print(word_in_matrix('BS', matrix))
print(word_in_matrix('FACIO', matrix))
print(word_in_matrix('CID', matrix))
