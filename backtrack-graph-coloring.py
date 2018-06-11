# Given an undirected graph represented as an adjacency matrix and an integer k,
# write a function to determine whether each vertex in the graph can be colored
# such that no two adjacent vertices share the same color using at most k colors.

def backtrack(graph, color, k, idx):
    if idx == len(color):
        return True

    for i in range(k):
        for j in range(len(graph)):
            if graph[idx][j] and color[j] == i:
                break
        else:
            color[idx] = i

            finished = backtrack(graph, color, k, idx + 1)
            if finished:
                return True

            color[idx] = -1

    return False


def colorable_with_colors(graph, k):
    color = [-1] * len(graph)
    return backtrack(graph, color, k, 0)


graph = [
    [False, True, False, False, False, True],
    [True, False, True, True, True, False],
    [False, True, False, True, True, False],
    [False, True, True, False, True, False],
    [False, True, True, True, False, True],
    [True, False, False, False, True, False]
]

print(colorable_with_colors(graph, 1))
print(colorable_with_colors(graph, 2))
print(colorable_with_colors(graph, 3))
print(colorable_with_colors(graph, 4))
print(colorable_with_colors(graph, 5))
