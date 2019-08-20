from typing import Optional

class Node:

    def __init__(self, left=None, right=None, parent=None):
        self.left = left
        self.right = right
        self.parent = parent


def find_successor(node: Node) -> Optional[Node]:
    if node is None:
        return node

    if node.right is None:
        return node.parent

    if node.right:
        current = node.right
        while current.left:
            current = current.left
        return current
