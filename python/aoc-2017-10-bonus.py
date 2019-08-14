from typing import List

VALUE_COUNT = 256
ROUNDS = 64


def rotate(values: List[int], cursor: int, rotation: int) -> None:
    for i in range(rotation // 2):
        start = (cursor + i) % len(values)
        end = (cursor + rotation - 1 - i) % len(values)

        values[start], values[end] = values[end], values[start]


def knot_hash(values: List[int], rotations: List[int]) -> None:
    cursor = 0

    for round in range(ROUNDS):
        for i, rotation in enumerate(rotations):
            rotate(values, cursor, rotation)

            skip = len(rotations) * round + rotation + i
            cursor = (cursor + skip) % len(values)


def to_hex(values: List[int]) -> str:
    hex_value = 0

    for value in values:
        hex_value ^= value

    result = hex(hex_value)[2:]
    return result if len(result) == 2 else f'0{result}'


def dense_hash(values: List[int]) -> str:
    result = ''

    while len(values) > 0:
        result += to_hex(values[:16])
        values = values[16:]

    return result


def main():
    values = [i for i in range(VALUE_COUNT)]
    rotations = list(map(ord, input().strip())) + [17, 31, 73, 47, 23]
    knot_hash(values, rotations)
    print(dense_hash(values))


if __name__ == '__main__':
    main()
