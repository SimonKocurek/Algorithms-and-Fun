from math import factorial

def paths_on_matrix(n, m):
    if n <= 0 or m <= 0:
        return 0

    values = [1] * m
    for i in range(n - 1):
        for j in range(1, m):
            values[j] += values[j - 1]

    return values[-1]

def fast_paths_on_matrix(n, m):
    higher = (n - 1) + (m - 1)
    lower = n - 1
    return factorial(higher) // factorial(lower) // factorial(higher - lower)

print(paths_on_matrix(2, 2), fast_paths_on_matrix(2, 2))
print(paths_on_matrix(3, 3), fast_paths_on_matrix(3, 3))
print(paths_on_matrix(1, 1), fast_paths_on_matrix(1, 1))
print(paths_on_matrix(1, 3), fast_paths_on_matrix(1, 3))
print(paths_on_matrix(3, 1), fast_paths_on_matrix(3, 1))
