class Node:
    def __init__(self, val, next):
        self.val = val
        self.next = next

def reverse(head):
    if head is None or head.next is None:
        return head

    next = head.next
    head.next = None
    while next is not None:
        third = next.next

        next.next = head
        head, next = next, third

    return head

def print_list(head):
    while head is not None:
        print(head.val, end=' ')
        head = head.next
    print()

linked_list1 = None
linked_list2 = Node(1, None)
linked_list3 = Node(1, Node(2, None))
linked_list4 = Node(0, Node(1, Node(2, Node(3, None))))

print_list(reverse(linked_list1))
print_list(reverse(linked_list2))
print_list(reverse(linked_list3))
print_list(reverse(linked_list4))
