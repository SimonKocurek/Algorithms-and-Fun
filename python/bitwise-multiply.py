# multiply numbers without using *

def multiply(a, b):
    negative = (a < 0) ^ (b < 0)
    a = abs(a)
    b = abs(b)

    result = 0
    for i in range(32):
        if (b & (1 << i)):
            result += a << i

    return -result if negative else result

print(multiply(-1, 1))
print(multiply(123, 0))
print(multiply(123, 3))
print(multiply(-30, 12))
