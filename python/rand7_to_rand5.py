from random import randint

def rand7():
    return randint(1, 7)

def rand5():
    result = rand7()
    while result > 5:
        result = rand7()
    return result

test = [0] * 6
for i in range(100000):
    test[rand5()] += 1
print(test)
