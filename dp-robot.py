
def path_possible(grid):
    if grid is None:
        raise Exception()

    if len(grid) == 0 or len(grid[0]) == 0:
        return True

    possible = [[False] * len(row) for row in grid]
    possible[0][0] = grid[0][0]

    for i in range(1, len(grid)):
        possible[i][0] = possible[i - 1][0] and grid[i][0]

    for i in range(1, len(grid[0])):
        possible[0][i] = possible[0][i - 1] and grid[0][i]

    for y in range(1, len(grid)):
        for x in range(1, len(grid[y])):
            possible[y][x] = (possible[y][x - 1] or possible[y - 1][x]) and grid[y][x]

    return possible[-1][-1]

print(path_possible([]))
print(path_possible([[True]]))
print(path_possible([[False]]))
print(path_possible([
    [True, False],
    [True, True]
]))
print(path_possible([
    [True, True, False, True],
    [True, True, False, True],
    [False, True, False, True],
    [True, True, True, True],
    [True, False, False, True]
]))

print(path_possible([
    [True, True, False, True],
    [True, True, False, True],
    [False, True, False, True],
    [True, False, True, True],
    [True, False, False, True]
]))