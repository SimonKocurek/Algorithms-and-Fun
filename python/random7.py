# Using a function rand5() that returns an integer from 1 to 5 (inclusive) with uniform probability,
# implement a function rand7() that returns an integer from 1 to 7 (inclusive).
from random import randint

def rand5():
    return randint(1, 5)
    
def rand7():
    result = 0
    while result == 0:
        result = 0

        for i in range(3):
            dice = rand5()
            while dice == 5:
                dice = rand5()
            result += (dice % 2) << i
        
    return result

results = [0] * 5
for i in range(100000):
    results[rand5() - 1] += 1
all = sum(results)

portions = []
for res in results:
    portions.append(res / all)
print(portions)

results = [0] * 7
for i in range(10000):
    results[rand7() - 1] += 1
all = sum(results)

portions = []
for res in results:
    portions.append(res / all)
print(portions)
