from collections import defaultdict

def visited(got, edge, seen, current, starters):
    seen.add(current)
    result = -1

    if current < starters:
        result = got

    for target in edge[current]:
        if target in seen:
            continue

        result = max(result, visited(got + 1, edge, seen, target, starters))

    seen.discard(current)
    return result

def main():
    vertices, starters, edges = list(map(int, input().split()))

    edge = defaultdict(set)

    for i in range(edges):
        fr, to = list(map(int, input().split()))
        edge[fr].add(to)
        edge[to].add(fr)

    result = 0
    for i in range(starters):
        result = max(result, visited(1, edge, set(), i, starters))
    print(result)

main()
