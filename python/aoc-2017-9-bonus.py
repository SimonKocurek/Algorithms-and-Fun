def garbage_characters(line: str) -> int:
    result = 0
    garbage = False

    i = 0
    while i < len(line):
        if garbage:
            if line[i] == '!':
                i += 2
            elif line[i] == '>':
                garbage = False
                i += 1
            else:
                result += 1
                i += 1
        else:
            if line[i] == '<':
                garbage = True
            i += 1

    return result


def main():
    line = input()
    print(garbage_characters(line))


if __name__ == '__main__':
    main()
