
# Given the sequence of keys visited by a postorder traversal of a binary search tree, reconstruct the tree.

#  For example, given the sequence 2, 4, 3, 8, 7, 5, you should construct the following tree:

#    5
#   / \
#  3   7
# / \   \
#2   4   8


class node: 
    def __init__(self, key): 
        self.key = key
        self.left = None
        self.right = None

def split(arr, k): 
    arr1 = None
    arr2 = None 

    if len(arr) <= 1 or arr == None: 
        return arr, []

    for i, var in enumerate(arr):
        if var > k:
            break
    
    arr1 = arr[:i]
    arr2 = arr[i:]

    return arr1, arr2
    
def printTree(root): 
    if not root: 
        return

    p = root
    print(p.key)
    if p.left:
        printTree(p.left)
    if p.right:
        printTree(p.right)

    return


def reconstructTree(arr): 
    if len(arr) == 0: 
        return None

    Node = node(arr[-1])    # As the array of is post order traversal

    lesser, higher = split(arr[:-1], Node.key)

    if len(lesser) > 0: 
        Node.left = reconstructTree(lesser)
    
    if len(higher) > 0: 
        Node.right = reconstructTree(higher)

    return Node

arr = [2, 4, 3, 8, 7, 5]
root = None
root = reconstructTree(arr)
printTree(root)


