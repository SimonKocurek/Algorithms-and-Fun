from heapq import heappush, heappop

def extremes_from_heap(heap, flipped):
    result = []

    while len(heap) > 0:
        added = heappop(heap) * (-1 if flipped else 1)
        result.append(added)

    result.reverse()
    return result


def get_extremes(arr, size):
    lowest = []
    highest = []

    for val in arr:
        if len(lowest) < size:
            heappush(lowest, -val)
            heappush(highest, val)
            continue

        if -lowest[0] > val:
            heappop(lowest)
            heappush(lowest, -val)

        if highest[0] < val:
            heappop(highest)
            heappush(highest, val)

    return (extremes_from_heap(lowest, True), extremes_from_heap(highest, False))

def largest_multiple_of_3(arr):
    lowest, highest = get_extremes(arr, 3)

    all_highest = highest[0] * highest[1] * highest[2]
    lowest_negated = highest[0] * lowest[0] * lowest[1] # if 2 lowest numbers are negative, they make positive number

    return max(all_highest, lowest_negated)

print(largest_multiple_of_3([-10, -10, 5, 2]))
