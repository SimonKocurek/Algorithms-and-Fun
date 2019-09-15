class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next

def reverse(root: Node) -> Node:
    if root is None:
        return root

    current = root
    next = root.next

    while next is not None:
        new_next = next.next
        next.next = current
        current, next = next, new_next

    root.next = None
    return current

def add_one(root: Node) -> Node:
    if root is None:
        return Node(1)

    flipped = reverse(root)

    current = flipped
    while current.value == 9 and current.next is not None:
        current.value = 0
        current = current.next

    if current.value == 9:
        current.value = 0
        current.next = Node(1)
    else:
        current.value += 1

    return reverse(flipped)

def print_list(root: Node) -> None:
    while root:
        print(root.value, end=', ')
        root = root.next
    print()

def main() -> None:
    print_list(add_one(Node(1, Node(2, Node(3)))))
    print_list(add_one(Node(1, Node(2, Node(9)))))
    print_list(add_one(None))
    print_list(add_one(Node(9, Node(9))))

if __name__ == "__main__":
    main()