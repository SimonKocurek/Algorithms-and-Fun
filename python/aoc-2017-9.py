from typing import Tuple


def parse_garbage(i: int, line: str) -> Tuple[bool, int]:
    if line[i] == '!':
        return True, i + 2

    elif line[i] == '>':
        return False, i + 1

    return True, i + 1


def parse_group(i: int, line: str, opened: int, score: int) -> Tuple[bool, int, int, int]:
    garbage = False

    if line[i] == '<':
        garbage = True
    elif line[i] == '{':
        opened += 1
    elif line[i] == '}':
        score += opened
        opened -= 1

    return garbage, i + 1, opened, score


def score_group(i: int, line: str) -> int:
    score = 0
    opened = 1
    i += 1

    garbage = False
    while opened > 0:
        if garbage:
            garbage, i = parse_garbage(i, line)
        else:
            garbage, i, opened, score = parse_group(i, line, opened, score)

    return score


def main():
    line = input()
    print(score_group(0, line))


if __name__ == '__main__':
    main()
