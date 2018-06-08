# Sudoku is a puzzle where you're given a partially-filled 9 by 9 grid with digits.
# The objective is to fill the grid with the constraint that every row, column, and
# box (3 by 3 subgrid) must contain all of the digits from 1 to 9.
#
# Implement an efficient sudoku solver.


def get_zeros(sudoku):
    result = []

    for i in range(len(sudoku)):
        for j in range(len(sudoku[i])):
            if sudoku[i][j] == 0:
                result.append((i, j))

    return result


def to_square(row, col):
    return (row // 3) * 3 + (col // 3)


def get_non_zeros(sudoku):
    number_in_row = [[False] * len(sudoku) for i in range(len(sudoku))]
    number_in_col = [[False] * len(sudoku) for i in range(len(sudoku))]
    number_in_square = [[False] * len(sudoku) for i in range(len(sudoku))]

    for i in range(len(sudoku)):
        for j in range(len(sudoku[0])):
            number = sudoku[i][j]
            if number == 0:
                continue

            number_in_row[i][number - 1] = True
            number_in_col[j][number - 1] = True
            number_in_square[to_square(i, j)][number - 1] = True

    return (number_in_row, number_in_col, number_in_square)


def backtrack(sudoku, idx, zeros, number_in_row, number_in_col, number_in_square):
    if idx == len(zeros):
        return True

    row, col = zeros[idx]
    for i in range(9):
        if number_in_row[row][i] or number_in_col[col][i] or number_in_square[to_square(row, col)][i]:
            continue

        number_in_row[row][i] = True
        number_in_col[col][i] = True
        number_in_square[to_square(row, col)][i] = True

        sudoku[row][col] = i + 1
        finished = backtrack(sudoku, idx + 1, zeros, number_in_row, number_in_col, number_in_square)

        if finished:
            return True

        number_in_row[row][i] = False
        number_in_col[col][i] = False
        number_in_square[to_square(row, col)][i] = False


def solve(sudoku):
    zeros = get_zeros(sudoku)
    non_zeros = get_non_zeros(sudoku)
    number_in_row, number_in_col, number_in_square = non_zeros
    backtrack(sudoku, 0, zeros, number_in_row, number_in_col, number_in_square)

sudoku = [
    [5, 3, 0, 0, 7, 0, 0, 0, 0],
    [6, 0, 0, 1, 9, 5, 0, 0, 0],
    [0, 9, 8, 0, 0, 0, 0, 6, 0],

    [8, 0, 0, 0, 6, 0, 0, 0, 3],
    [4, 0, 0, 8, 0, 3, 0, 0, 1],
    [7, 0, 0, 0, 2, 0, 0, 0, 6],

    [0, 6, 0, 0, 0, 0, 2, 8, 0],
    [0, 0, 0, 4, 1, 9, 0, 0, 5],
    [0, 0, 0, 0, 8, 0, 0, 7, 9]
]

solve(sudoku)
for row in sudoku:
    print(row)
