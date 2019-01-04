def print_spiral(spiral):
    if spiral is None or len(spiral) == 0 or spiral[0] is None or len(spiral[0]) == 0:
        return

    n, m = len(spiral), len(spiral[0])
    x_steps, y_steps = m - 1, n - 1
    x, y = 0, 0
    x_change, y_change = 1, 1

    for i in range(x_steps):
            print(spiral[y][x])
            x += x_change
    x_change *= -1

    while x_steps > 0 and y_steps > 0:
        for i in range(y_steps):
            print(spiral[y][x])
            y += y_change
        y_steps -= 1
        y_change *= -1

        for i in range(x_steps):
            print(spiral[y][x])
            x += x_change
        x_change *= -1
        x_steps -= 1

    print(spiral[y][x])

spiral = [[1,  2,  3,  4,  5],
 [6,  7,  8,  9,  10],
 [11, 12, 13, 14, 15],
 [16, 17, 18, 19, 20]]

print_spiral(spiral)
