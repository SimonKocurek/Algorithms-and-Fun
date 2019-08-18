from collections import defaultdict
from typing import List, Iterator, DefaultDict, Set, Iterable

Graph = DefaultDict[str, Set[str]]


def get_alphabet(words: List[str]) -> Set[str]:
    result = set()

    for word in words:
        for letter in word:
            result.add(letter)

    return result


def first_different(a: str, b: str) -> int:
    result = 0

    while result < len(a) and result < len(b) and a[result] == b[result]:
        result += 1

    return result


def build_graph(words: List[str]) -> Graph:
    incoming = defaultdict(set)

    for first, second in zip(words, words[1:]):
        difference = first_different(first, second)

        # word length was deciding factor
        if difference >= len(first) or difference >= len(second):
            continue

        smaller, larger = first[difference], second[difference]
        incoming[larger].add(smaller)

    return incoming


def get_starting_letters(graph: Graph, alphabet: Iterable[str]) -> Iterator[str]:
    for letter in alphabet:
        if len(graph[letter]) == 0:
            yield letter


def remove_from_graph(graph: Graph, letter: str) -> None:
    for incoming in graph.values():
        incoming.discard(letter)


def order(words: List[str]) -> str:
    graph = build_graph(words)
    alphabet = get_alphabet(words)

    result = ''

    for letter in range(len(alphabet)):
        # Could be improved using heap
        starting_letters = list(get_starting_letters(graph, alphabet))

        # no deterministic solution
        if len(starting_letters) > 1 or len(starting_letters) == 0:
            return ''

        starting_letter = starting_letters[0]
        result += starting_letter
        alphabet.discard(starting_letter)
        remove_from_graph(graph, starting_letter)

    return result


def main() -> None:
    print(order([]), 'Expected:')
    print(order(["z"]), 'Expected: z')
    print(order(["za"]), 'Expected:')
    print(order(["z", "x"]), 'Expected: zx')
    print(order(["z", "x", "z"]), 'Expected:')
    print(order(["z", "x", "a", "b"]), 'Expected: zxab')
    print(order(["z", "x", "xa", "xb", "a"]), 'Expected: zxab')
    print(order(["z", "x", "xa", "a", "xb"]), 'Expected:')
    print(order(["z", "x", "xa", "xb"]), 'Expected:')
    print(order(["xa", "xb", "bc", "ac"]), 'Expected:')
    print(order(["xa", "xb", "ac", "bc"]), 'Expected:')
    print(order(["xa", "xb", "ac", "bc", "c"]), 'Expected: xabc')
    print(order(["xa", "xb", "c", "ac", "bc"]), 'Expected: xcab')
    print(order(["a", "aac", "ab"]), 'Expected:')
    print(order(["a", "aac", "ab", "ba", "bbc", "bc"]), 'Expected: abc')
    print(order([
        "wrt",
        "wrf",
        "er",
        "ett",
        "rftt"
    ]), 'Expected: wertf')


if __name__ == '__main__':
    main()
