from collections import defaultdict
from typing import List, DefaultDict


def load_program() -> List[List[str]]:
    result = []

    line = input()
    while line != "":
        result.append(line.split())
        line = input()

    return result


def execute_instruction(instruction: List[str], registers: DefaultDict[str, int]) -> int:
    command, *arguments = instruction
    instruction_pointer_change = 1

    if command == 'cpy':
        origin, target = arguments
        if origin[0].isalpha():
            registers[target] = registers[origin]
        else:
            registers[target] = int(origin)

    elif command == 'jnz':
        source, jump = arguments
        if source[0].isalpha() and registers[source] != 0:
            instruction_pointer_change = int(jump)
        elif not source[0].isalpha() and int(source) != 0:
            instruction_pointer_change = int(jump)

    elif command == 'inc':
        registers[arguments[0]] += 1

    elif command == 'dec':
        registers[arguments[0]] -= 1

    else:
        raise ValueError(f'Invalid command {command}')

    return instruction_pointer_change


def execute_program(program: List[List[str]], registers: DefaultDict[str, int]) -> None:
    instruction_pointer = 0

    while instruction_pointer < len(program):
        instruction_pointer += execute_instruction(program[instruction_pointer], registers)


def main() -> None:
    registers = defaultdict(int)
    program = load_program()
    execute_program(program, registers)
    print(registers['a'])


if __name__ == '__main__':
    main()
