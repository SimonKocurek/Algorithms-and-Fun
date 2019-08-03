# You have an N by N board. Write a function that, given N,
# returns the number of possible arrangements of the board
# where N queens can be placed on the board without threatening
# each other, i.e. no two queens share the same row, column,
# or diagonal.


def queens(dimension):
    result = []

    taken_column = [False] * dimension
    taken_diagonal_left = [False] * (dimension * 2 - 1)
    taken_diagonal_right = [False] * (dimension * 2 - 1)

    def fill_row(row, arrangement):
        if row == dimension:
            result.append(arrangement[:])
            return

        for column in range(dimension):
            diagonal_left = row + column
            diagonal_right = (dimension - 1) + column - row

            if taken_column[column] or \
                    taken_diagonal_left[diagonal_left] or \
                    taken_diagonal_right[diagonal_right]:
                continue

            taken_column[column] = True
            taken_diagonal_left[diagonal_left] = True
            taken_diagonal_right[diagonal_right] = True
            arrangement.append((row, column))

            fill_row(row + 1, arrangement)

            arrangement.pop()
            taken_column[column] = False
            taken_diagonal_left[diagonal_left] = False
            taken_diagonal_right[diagonal_right] = False

    fill_row(0, [])
    return result


print(queens(3))
print()

print(queens(4))
print()

print(queens(5))
print()

print(queens(6))
print()
