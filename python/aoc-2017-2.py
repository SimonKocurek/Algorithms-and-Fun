def main():
    line = input()
    checksum = 0

    while line != "":
        values = list(map(int, line.split()))
        checksum += max(values) - min(values)

        line = input()

    print(checksum)

main()
