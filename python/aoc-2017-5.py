from typing import List


def load_instructions() -> List[int]:
    instructions = []

    line = input()
    while line != "":
        instructions.append(int(line))
        line = input()

    return instructions


def instruction_steps(instructions: List[int]) -> int:
    steps = 0
    pointer = 0

    while pointer < len(instructions):
        move = instructions[pointer]

        instructions[pointer] += 1
        steps += 1

        pointer += move

    return steps


def main():
    instructions = load_instructions()
    print(instruction_steps(instructions))


main()
