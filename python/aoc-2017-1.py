def main():
    digits = list(map(int, input()))

    sum = 0
    for i in range(len(digits)):
        if digits[i] == digits[i - 1]:
            sum += digits[i]

    print(sum)


main()
