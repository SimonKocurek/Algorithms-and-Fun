from collections import Counter


def main():
    result = 0

    line = input()
    while line != "":
        values = line.split()
        frequency_maps = set(tuple(sorted(Counter(value).items())) for value in values)

        if len(frequency_maps) == len(values):
            result += 1

        line = input()

    print(result)


main()
