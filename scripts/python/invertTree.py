class Node: 
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None


def invert_tree(root): 
    if root is None: 
        return None

    rootright = invert_tree(root.left)
    rootleft = invert_tree(root.right)
    root.right = rootright
    root.left = rootleft

    return root

a = Node('a')
b = Node('b')
c = Node('c')
d = Node('d')
e = Node('e')
f = Node('f')

a.left = b
a.right = c
b.left = d
b.right = e
c.left = f

inverted_a = invert_tree(a)
print(inverted_a.left.key)
