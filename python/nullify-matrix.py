def nullify_cols(matrix):
    for x in range(1, len(matrix[0])):
        if matrix[0][x] == 0:
            for y in range(len(matrix)):
                matrix[y][x] = 0
    

def nullify_rows(matrix):
    for y in range(1, len(matrix)):
        if matrix[y][0] == 0:
            for x in range(len(matrix[0])):
                matrix[y][x] = 0


def nullify_first(matrix, row, col):
    if row:
        for x in range(1, len(matrix[0])):
            matrix[0][x] = 0

    if col:
        for y in range(1, len(matrix)):
            matrix[y][0] = 0


def first_row_has_zero(matrix):
    for x in matrix[0]:
        if x == 0:
            return True
    return False 


def first_col_has_zero(matrix):
    for y in matrix:
        if matrix[0] == 0:
            return True
    return False
    

def nullify(matrix):
    if not matrix:
        return

    first_row = first_row_has_zero(matrix)
    first_col = first_col_has_zero(matrix)

    for y in range(len(matrix)):
        for x in range(len(matrix[y])):
            if matrix[y][x] == 0:
                matrix[y][0] = 0
                matrix[0][x] = 0
    
    first = matrix[0][0] == 0

    nullify_rows(matrix)
    nullify_cols(matrix)
    nullify_first(matrix, first_row, first_col)

matrix = []

i = int(input())
for y in range(i):
    numbers = list(map(int, list(input())))
    matrix.append(numbers)

nullify(matrix)

print()
for row in matrix:
    print(row)

