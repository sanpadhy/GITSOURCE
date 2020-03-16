class node: 
    def __init__(self, key): 
        self.key = key
        self.left = None
        self.right = None

    def __repr__(self): 
        return "[{}=l{}:r{}]".format(self.key, self.left, self.right)

def inorderTraversal(root): 
    if not root: 
        return

    if root.left: 
        inorderTraversal(root.left)

    print(root)

    if root.right: 
        inorderTraversal(root.right)

    return


A = node('a')
B = node('b')
C = node('c')
D = node('d')
E = node('e')

A.left = B
A.right = C
B.left = D
C.left = E

inorderTraversal(A)




