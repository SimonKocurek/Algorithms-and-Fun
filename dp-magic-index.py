# Array with sorted distinct values, find i such that A[i] = i
# What if they are not distinct


def find_index(array):
    if array is None or len(array) == 0:
        return -1

    start = 0
    end = len(array) - 1

    while start <= end:
        middle = (start + end) // 2

        if array[middle] == middle:
            return middle
        elif array[middle] > middle:
            end = middle - 1
        else:
            start = middle + 1

    return -1


test1 = [1, 2, 3, 4, 5]
test2 = []
test3 = [1]
test4 = [-6, -4, -3, -2, 1, 2, 3, 7, 9, 10, 19]
test5 = [-6, -4, -3, 3, 6, 9, 10, 19]

print(find_index(test1))
print(find_index(test2))
print(find_index(test3))
print(find_index(test4))
print(find_index(test5))


def find_index_non_distinct(array):
    if array is None or len(array) == 0:
        return -1

    start = 0
    end = len(array) - 1
    while start <= end:
        middle = (start + end) // 2

        if array[middle] == middle:
            return middle
        elif array[middle] < len(array) and array[array[middle]] == array[middle]:
            return array[middle]
        elif array[middle] > middle:
            end = middle - 1
        else:
            start = middle + 1

    return -1


test1 = [1, 1, 2, 2, 3, 3, 4, 7, 8, 8]
test2 = []
test3 = [1, 2, 2]
test4 = [-6, -4, -3, -2, 1, 2, 3, 7, 7, 7, 7, 9, 10, 19]
test5 = [-6, -4, -3, 3, 6, 9, 10, 19]

print()
print(find_index_non_distinct(test1))
print(find_index_non_distinct(test2))
print(find_index_non_distinct(test3))
print(find_index_non_distinct(test4))
print(find_index_non_distinct(test5))
