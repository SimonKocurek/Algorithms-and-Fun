import sys
from typing import List


def find_solution(values: List[int]) -> str:
    possible = set()  # Sums of all ranges [0, i]
    got = 0  # Running sum from [0, n]

    for value in values:
        got += value

        # If one of the sums of ranges [0, i] has value needed to get sum of [0, j] to 0
        # we can consider range [i+1 - j] as our result
        if got in possible or value == 0:
            return 'yes'

        possible.add(got)

    return 'no'


def process_file(filename: str) -> None:
    with open(filename, 'r') as input_file:
        sets = int(input_file.readline())

        for i in range(sets):
            value_count = int(input_file.readline())
            values = list(map(int, input_file.readline().split()))

            solution = find_solution(values)
            print(solution)


def main():
    process_file(sys.argv[1])


if __name__ == "__main__":
    main()
