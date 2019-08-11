def manhattan_distance(value, level_start, level):
    value_in_level = value - level_start - 1
    value_in_line = value_in_level % (2 * level)
    distance_from_middle = abs(value_in_line - (level - 1))
    return level + distance_from_middle

def main():
    value = int(input())
    if value == 1:
        return 0

    got = 1
    level = 0

    while True:
        level += 1
        next_got = got + 4 * (level * 2)

        if next_got >= value:
            return manhattan_distance(value, got, level)

        got = next_got


result = main()
print(result)
