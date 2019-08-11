from collections import defaultdict
from typing import DefaultDict, Dict, Tuple, Iterator

Memory = DefaultDict[int, Dict[int, int]]
Point = Tuple[int, int]


def in_memory(memory: Memory, x: int, y: int) -> bool:
    return y in memory and x in memory[y]


def cell_value(memory: Memory, x: int, y: int) -> int:
    dimensions = ((1, 1), (1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1), (0, 1))
    value = 0

    for dimension in dimensions:
        new_x, new_y = x + dimension[0], y + dimension[1]

        if not in_memory(memory, new_x, new_y):
            continue

        value += memory[new_y][new_x]

    return value


def line_length() -> Iterator[int]:
    level = 1

    while True:
        for direction in range(4):
            yield level * 2

        level += 1


def next_direction() -> Iterator[Point]:
    directions = ((0, -1), (-1, 0), (0, 1), (1, 0))

    while True:
        for direction in directions:
            yield direction


def next_point() -> Iterator[Point]:
    directions = next_direction()
    lengths = line_length()

    x, y = 0, 0

    while True:
        x, y = x + 1, y
        yield x, y

        for i in range(4):
            direction = next(directions)
            length = next(lengths) - (1 if i == 0 else 0)

            for point in range(length):
                x, y = x + direction[0], y + direction[1]
                yield x, y


def main():
    value: int = int(input())
    memory: DefaultDict[int, Dict[int, int]] = defaultdict(dict)
    memory[0][0] = 1

    points = next_point()
    x, y = 0, 0

    while memory[y][x] <= value:
        x, y = next(points)
        memory[y][x] = cell_value(memory, x, y)

    return memory[y][x]


result = main()
print(result)
