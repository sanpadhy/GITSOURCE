# Given a binary tree, determine whether or not it is height-balanced. A height-balanced binary tree can 
# be defined as one in which the heights of the two subtrees of any node never differ by more than one.

class node: 
    def __init__(self, key): 
        self.left = None
        self.right = None

def heightofTree(root): 
    if not root: 
        return 0

    lheight = heightofTree(root.left)
    rheight = heightofTree(root.right)

    return max(lheight, rheight)+1

def isHeightBalanced(root): 
    if not root: 
        return true

    lheight = heightofTree(root.left)
    rheight = heightofTree(root.right)

    return True if abs(lheight - rheight) < 2 else False


n1 = node(23)
n2 = node(14)
n3 = node(25)
n4 = node(39)
n5 = node(47)

n1.left = n2
n1.right = n3
n3.right = n4
n4.right = n5

print(isHeightBalanced(n1))
