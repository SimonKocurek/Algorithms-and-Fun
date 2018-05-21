# Given the root to a binary search tree, find the second largest node in the tree.


class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def second_largest(root):
    previous = root
    current = root

    while current.right:
        previous, current = current, current.right

    if current.left:
        current = current.left
        while current.right:
            current = current.right
        return current

    return previous

test1 = Node(10)
test2 = Node(10, Node(5, Node(1), Node(7)), Node(15, Node(12), Node(17)))
test3 = Node(10, None, Node(15))
test4 = Node(10, None, Node(15, Node(12), Node(18, Node(16, None, Node(17)))))
test5 = Node(10, Node(5), Node(15))
test6 = Node(10, Node(5), Node(15, Node(12)))
test7 = Node(10, Node(5), Node(15, Node(12, Node(11), Node(13))))

print(second_largest(test1).val, 10)
print(second_largest(test2).val, 15)
print(second_largest(test3).val, 10)
print(second_largest(test4).val, 17)
print(second_largest(test5).val, 10)
print(second_largest(test6).val, 12)
print(second_largest(test7).val, 13)
