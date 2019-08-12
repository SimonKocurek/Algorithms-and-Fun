from typing import List


def biggest_value(values: List[int]) -> int:
    idx = 0

    for i in range(1, len(values)):
        if values[i] > values[idx]:
            idx = i

    return idx


def distribute(values: List[int], idx: int) -> None:
    distributed = values[idx]
    values[idx] = 0

    cycles = distributed // len(values)
    for i in range(len(values)):
        values[i] += cycles

    remaining = distributed % len(values)
    i = idx
    while remaining > 0:
        i = (i + 1) % len(values)
        values[i] += 1
        remaining -= 1


def main():
    values = list(map(int, input().split()))
    seen = set()

    steps = 0
    state = tuple(values)
    while state not in seen:
        seen.add(state)

        idx = biggest_value(values)
        distribute(values, idx)
        state = tuple(values)
        steps += 1

    print(steps)


main()
