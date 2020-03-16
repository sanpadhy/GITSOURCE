class Node: 
    def __init__(self, key): 
        self.key = key
        self.left = None
        self.right = None

def NoOfBinaryHeap(root): 
    if root and root.left and root.right: 
        return 2 * NoOfBinaryHeap(root.left) * NoOfBinaryHeap(root.right)

    return 1

# Tests
a = Node(3)
b = Node(2)
c = Node(1)
a.left = b
a.right = c

print(NoOfBinaryHeap(a))
