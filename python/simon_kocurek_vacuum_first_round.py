import sys
from typing import List, Tuple, Set, Dict


def get_all_words(synonyms: List[Tuple[str, str]]) -> Set[str]:
    result = set()

    for synonym in synonyms:
        first_word = synonym[0].lower()
        second_word = synonym[1].lower()

        result.add(first_word)
        result.add(second_word)

    return result


def get_word_indexes(words: List[str]) -> Dict[str, int]:
    word_indexes: Dict[str, int] = {}

    for i, word in enumerate(words):
        word_indexes[word] = i

    return word_indexes


def union(components: List[int], component_sizes: List[int], first: int, second: int) -> None:
    """
    Union part of Union-Find
    """
    first_root = find(components, first)
    second_root = find(components, second)

    if first_root == second_root:
        return

    if component_sizes[first_root] >= component_sizes[second_root]:
        component_sizes[first_root] += component_sizes[second_root]
        components[second_root] = first_root
    else:
        component_sizes[second_root] += component_sizes[first_root]
        components[first_root] = second_root


def find(components: List[int], idx: int) -> int:
    """
    Find part of Union-Find
    """
    if components[idx] == idx:
        return idx

    components[idx] = find(components, components[idx])
    return components[idx]


def get_components(synonyms: List[Tuple[str, str]]) -> Dict[str, int]:
    all_words = list(get_all_words(synonyms))
    word_indexes = get_word_indexes(all_words)

    # Each graph component symbolizes a group of synonyms
    components = [i for i in range(len(all_words))]
    component_sizes = [1 for i in range(len(all_words))]

    for synonym in synonyms:
        first_word = synonym[0].lower()
        second_word = synonym[1].lower()

        union(components, component_sizes, word_indexes[first_word], word_indexes[second_word])

    result = {}

    for i, word in enumerate(all_words):
        result[word] = find(components, i)

    return result


def are_synonyms(synonyms: List[Tuple[str, str]], queries: List[Tuple[str, str]]) -> List[str]:
    word_components = get_components(synonyms)
    result = []

    for query in queries:
        first_word = query[0].lower()
        second_word = query[1].lower()

        if first_word == second_word:
            result.append('synonyms\n')

        elif first_word in word_components and \
                second_word in word_components and \
                word_components[first_word] == word_components[second_word]:
            result.append('synonyms\n')

        else:
            result.append('different\n')

    return result


def main():
    with open(sys.argv[1], 'r') as input_file:
        with open('result.out', 'w') as output_file:
            sets = int(input_file.readline())

            for set in range(sets):
                synonym_count = int(input_file.readline())
                synonyms = [input_file.readline().split() for line in range(synonym_count)]
                query_count = int(input_file.readline())
                queries = [input_file.readline().split() for line in range(query_count)]

                for result in are_synonyms(synonyms, queries):
                    output_file.write(result)


if __name__ == "__main__":
    main()
