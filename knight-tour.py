KNIGHT_MOVEMENTS = (
    (-1, -2), (1, -2), (-1, 2), (1, 2),
    (-2, 1), (-2, -1), (2, 1), (2, -1)
)

def valid_move(x, y, used_tile):
    return y >= 0 and y < len(used_tile) and \
        x >= 0 and x < len(used_tile[0]) and \
        not used_tile[y][x]

def knight_tours_from(x, y, used_tile, remaining_tiles):
    if remaining_tiles == 0:
        return 1

    result = 0

    for x_change, y_change in KNIGHT_MOVEMENTS:
        new_x, new_y = x + x_change, y + y_change

        if not valid_move(new_x, new_y, used_tile):
            continue

        used_tile[new_y][new_x] = True
        result += knight_tours_from(new_x, new_y, used_tile, remaining_tiles - 1)
        used_tile[new_y][new_x] = False

    return result

def knight_tours(size):
    if size <= 1:
        return 0

    used_tile = [[False for j in range(size)] for i in range(size)]
    remaining_tiles = size * size

    return knight_tours_from(0, 0, used_tile, remaining_tiles)

for i in range(-2, 10):
    print(f'{i}: {knight_tours(i)}')
