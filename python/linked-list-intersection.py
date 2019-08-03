'''
This problem was asked by Google.

Given two singly linked lists that
intersect at some point, find the
intersecting node. The lists are
non-cyclical.

For example, given A = 3 -> 7 -> 8 -> 10
and B = 99 -> 1 -> 8 -> 10, return
the node with value 8.

In this example, assume nodes with
the same value are the exact same
node objects.

Do this in O(M + N) time (where M
and N are the lengths of the lists)
and constant space.
'''

class node:
    
    def __init__(self, data, next=None):
        self.data = data
        self.next = next

def linked_list_length(a):
    result = 0

    while a:
        a = a.next
        result += 1
        
    return result

def find_intersection(a, b):
    a_len = linked_list_length(a)
    b_len = linked_list_length(b)

    while a_len > b_len:
        a = a.next
        a_len -= 1

    while b_len > a_len:
        b = b.next
        b_len -= 1

    while a and b and a.data != b.data:
        a = a.next
        b = b.next

    if a and b and a.data == b.data:
        return a.data

a = node(1, node(2, node(3, node(4, node(5)))))
b = node(6, node(7, node(8, node(9))))
c = node(10, node(11, node(12, node(13, node(14, node(15))))))
a.next.next.next.next.next = c
b.next.next.next.next = c

print(find_intersection(a, b))

a = node(3, node(7, node(8, node(10))))
b = node(99, node(1, a.next.next))

print(find_intersection(a,b))

