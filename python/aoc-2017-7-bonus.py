import sys
from collections import namedtuple, Counter
from typing import Dict

Node = namedtuple('Node', ['value', 'children'])


def load_tree() -> Dict[str, Node]:
    nodes = {}

    line = input()
    while line != "":
        name, value, *children = line.split()
        nodes[name] = Node(int(value[1:-1]), ''.join(children[1:]).split(',') if len(children) > 0 else [])
        line = input()

    return nodes


def get_subtree_weight(subtree_weights: Dict[str, int], nodes: Dict[str, Node], node_name: str) -> int:
    if node_name in subtree_weights:
        return subtree_weights[node_name]

    node = nodes[node_name]

    children_weights = sum([get_subtree_weight(subtree_weights, nodes, child) for child in node.children])
    subtree_weights[node_name] = node.value + children_weights
    return subtree_weights[node_name]


def main():
    nodes = load_tree()
    subtree_weights = {}

    expected_weight = sys.maxsize
    bad_subtree_root = Node(sys.maxsize, [])

    for node in nodes.values():
        weights = Counter([get_subtree_weight(subtree_weights, nodes, child) for child in node.children])

        if len(weights) == 2:
            weights = sorted(weights.items(), key=lambda x: x[1])
            if bad_subtree_root.value < weights[0][0]:
                continue

            bad_subtree_root = [nodes[child] for child in node.children if subtree_weights[child] == weights[0][0]][0]
            expected_weight = bad_subtree_root.value - (weights[0][0] - weights[1][0])

    print(expected_weight)


main()
