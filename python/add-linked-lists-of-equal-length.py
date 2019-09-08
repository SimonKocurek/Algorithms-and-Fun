class Node:
    def __init__(self, value: int, next=None):
        self.value = value
        self.next = next
        

def reverse(head: Node) -> Node:
    if head is None:
        return head

    current = head
    next = head.next
    while next is not None: 
        new_next = next.next
        next.next = current
        
        current, next = next, new_next

    head.next = None
    return current


def add_linked_lists(a: Node, b: Node) -> Node:
    a, b = reverse(a), reverse(b)

    result = Node(-1)
    current = result
    carry = 0
    while a and b:
        new_value = (a.value + b.value + carry) % 10
        carry = (a.value + b.value + carry) // 10

        current.next = Node(new_value)
        current = current.next

        a, b = a.next, b.next

    return reverse(result.next)


def main() -> None:
    a = Node(3, Node(6, Node(5)))
    b = Node(2, Node(4, Node(8)))

    result = add_linked_lists(a, b)
    while result:
        print(result.value)
        result = result.next


if __name__ == "__main__":
    main()