def values_checksum(values):
    for i in range(len(values)):
        for j in range(len(values)):
            if i != j and values[i] % values[j] == 0:
                return values[i] // values[j]

    return 0


def main():
    line = input()
    checksum = 0

    while line != "":
        values = list(map(int, line.split()))
        checksum += values_checksum(values)

        line = input()

    print(checksum)

main()
