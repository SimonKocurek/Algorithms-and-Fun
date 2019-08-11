def main():
    result = 0

    line = input()
    while line != "":
        values = line.split()

        if len(values) == len(set(values)):
            result += 1

        line = input()

    print(result)

main()
