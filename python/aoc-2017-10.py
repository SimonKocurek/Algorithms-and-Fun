from typing import List

VALUE_COUNT = 256


def rotate(values: List[int], cursor: int, rotation: int) -> None:
    for i in range(rotation // 2):
        start = (cursor + i) % len(values)
        end = (cursor + rotation - 1 - i) % len(values)

        values[start], values[end] = values[end], values[start]


def main():
    rotations = list(map(int, input().split(',')))
    values = [i for i in range(VALUE_COUNT)]

    cursor = 0
    for i, rotation in enumerate(rotations):
        rotate(values, cursor, rotation)
        cursor = (cursor + rotation + i) % len(values)

    print(values[0] * values[1])


if __name__ == '__main__':
    main()
