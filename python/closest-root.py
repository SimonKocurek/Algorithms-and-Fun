class Node:

    def __init__(self, left=None, right=None):
        self.left = left
        self.right = right

# DFS search, finding whole path to target
def get_path_to(root, target):
    if root == target:
        return []

    if root.left:
        path = get_path_to(root.left, target)
        if path is not None:
            path.append(root)
            return path

    if root.right:
        path = get_path_to(root.right, target)
        if path is not None:
            path.append(root)
            return path

    # No path found
    return None

def closest_root(root, a, b):
    path = get_path_to(root, a)

    if not path:
        print('A not present in the tree')
        return None

    for node in reversed(path):
        if get_path_to(node, b) is not None:
            # Node has both path to 'a' and 'b'
            return node

    print('B not found in the tree')
    return None

def main():
    a, b = Node(), Node()
    tree = Node(Node(a, b), None)

    res = closest_root(tree, a, b)
    print(res == tree)

main()
