# We can determine how "out of order" an array A is by counting the number
# of inversions it has. Two elements A[i] and A[j] form an inversion if
# A[i] > A[j] but i < j. That is, a smaller element appears after a larger element.
#
# Given an array, count the number of inversions it has. Do this faster
# than O(N^2) time.
#
# You may assume each element in the array is distinct.
#
# For example, a sorted list has zero inversions. The array [2, 4, 1, 3, 5]
# has three inversions: (2, 1), (4, 1), and (4, 3). The array [5, 4, 3, 2, 1]
# has ten inversions: every distinct pair forms an inversion.


def inversions(array=[], start=0, end=None):
    def merge(start, middle, end):
        copy = []
        flips = 0
        flipped = 0

        i = start
        j = middle + 1
        while i <= middle or j <= end:
            if i <= middle and (j > end or array[i] < array[j]):
                flips += flipped
                copy.append(array[i])
                i += 1
            else:
                flipped += 1
                copy.append(array[j])
                j += 1

        for x in range(start, end + 1):
            array[x] = copy[x - start]

        return flips

    if end is None:
        end = len(array) - 1

    if start >= end:
        return 0

    middle = (start + end) // 2

    result = inversions(array, start, middle) + \
        inversions(array, middle + 1, end)
    result += merge(start, middle, end)

    return result


print(inversions([2, 4, 1, 3, 5]), 'expected', 3)
print(inversions([]), 'expected', 0)
print(inversions(), 'expected', 0)
print(inversions([1]), 'expected', 0)
print(inversions([5, 4, 3, 2, 1]), 'expected', 10)
