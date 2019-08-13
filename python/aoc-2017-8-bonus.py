from collections import defaultdict


def evaluate(registers: defaultdict, compared_register: str, comparison: str, compared_value: str) -> bool:
    compared_value = int(compared_value)

    if comparison == '>':
        return registers[compared_register] > compared_value
    elif comparison == '>=':
        return registers[compared_register] >= compared_value
    elif comparison == '==':
        return registers[compared_register] == compared_value
    elif comparison == '<':
        return registers[compared_register] < compared_value
    elif comparison == '!=':
        return registers[compared_register] != compared_value
    elif comparison == '<=':
        return registers[compared_register] <= compared_value
    else:
        raise ValueError(f'comparison {comparison} operator is not supported')


def main():
    registers = defaultdict(int)
    seen_max = 0

    line = input()
    while line != "":
        register, operation, value, _, compared_register, comparison, compared_value = line.split()

        if evaluate(registers, compared_register, comparison, compared_value):
            value = int(value)
            if operation == 'inc':
                registers[register] += value
            elif operation == 'dec':
                registers[register] -= value
            else:
                raise ValueError(f'operation {operation} is not supported')

            seen_max = max(seen_max, registers[register])

        line = input()

    print(seen_max)


if __name__ == '__main__':
    main()
