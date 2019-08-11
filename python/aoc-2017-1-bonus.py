def main():
    digits = list(map(int, input()))

    skip = len(digits) // 2
    sum = 0
    for i in range(len(digits)):
        if digits[i] == digits[i - skip]:
            sum += digits[i]

    print(sum)


main()
