def pow(x, exponent):
    if exponent == 0:
        return 1

    if exponent == 1:
        return x

    return pow(x * x, exponent // 2) * (x if exponent % 2 == 1 else 1)

for i in range(20):
    print(pow(2, i))

print(pow(-10, 3))
print(pow(-10, 2))
print(pow(-10, 1))
print(pow(-10, 0))
