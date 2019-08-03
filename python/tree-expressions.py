# Suppose an arithmetic expression is given as a binary tree.
# Each leaf is an integer and each internal node is one of
# '+', '−', '∗', or '/'.
#
# Given the root to such a tree, write a function to evaluate it.
#
# For example, given the following tree:
#
#     *
#    / \
#   +    +
#  / \  / \
# 3  2  4  5
# You should return 45, as it is (3 + 2) * (4 + 5).

class Node:

    def __init__(self, value: str, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


def evaluate(root: Node):
    if root is None:
        return 0

    if root.value == '+':
        return evaluate(root.left) + evaluate(root.right)
    elif root.value == '-':
        return evaluate(root.left) - evaluate(root.right)
    elif root.value == '*':
        return evaluate(root.left) * evaluate(root.right)
    elif root.value == '/':
        return evaluate(root.left) / evaluate(root.right)
    else:
        return int(root.value)


print(
    evaluate(Node('*', Node('+', Node('3'), Node('2')), Node('+', Node('4'), Node('5'))))
)
