from typing import List, Tuple, Iterator


def get_ranges(values: List[int], lower: int, upper: int) -> Iterator[Tuple[int, int]]:
    if len(values) == 0:
        yield (lower, upper)
        return

    current = lower
    for i in range(len(values)):
        if values[i] == current:
            current += 1

        else:
            yield (current, values[i] - 1)
            current = values[i] + 1

    if current <= upper:
        yield (current, upper)



def solve(values: List[int], lower: int, upper: int) -> Iterator[str]:
    for start, end in get_ranges(values, lower, upper):
        yield f'{start}->{end}' if start < end else f'{start}'


def main() -> None:
    lower, upper = map(int, input().split())
    values = list(map(int, input().split()))
    solve(values, lower, upper)

    # print(list(solve([], 1, 1)), 'Expected [1]')
    # print(list(solve([], 1, 2)), 'Expected [1->2]')
    # print(list(solve([1], 1, 1)), 'Expected []')
    # print(list(solve([1], 1, 2)), 'Expected [2]')
    # print(list(solve([-9, -8, -6, 0, 9, 10], -10, 10)), 'Expected [-10, -7, -5->1, 1->8]')
    # print(list(solve([-9, -8, -6, 0, 9], -10, 10)), 'Expected [-10, -7, -5->1, 1->8, 10]')
    # print(list(solve([-9, -8, -6, 0, 8], -10, 10)), 'Expected [-10, -7, -5->1, 1->7, 9->10]')


if __name__ == '__main__':
    main()
