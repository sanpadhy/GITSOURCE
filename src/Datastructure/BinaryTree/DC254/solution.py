class node: 
    def __init__(self, key): 
        self.key = key
        self.left = None 
        self.right = None 

def printList(root): 
        if not root: 
            return None

        print(root.key)
        if root.left: 
            printList(root.left)
        if root.right: 
            printList(root.right)

def removeUnbalancedNode(root): 
    if not root: 
        return None

    if not root.left or not root.right: 
        return root
    elif root.left and root.right: 
        root.left = removeUnbalancedNode(root.left)
        root.right = removeUnbalancedNode(root.right)
        return root
    elif root.left: 
        return removeUnbalancedNode(root.left)
    elif root.right: 
        return removeUnbalancedNode(root.right)

a = node('a')
b = node('b')
c = node('c')
d = node('d')
e = node("e")
f = node("f")
g = node("g")
h = node("h")

a.left = b
a.right = c
b.left = d
d.right = f
c.right = e
e.left = g
e.right = h

printList(removeUnbalancedNode(a))
