# Given a sorted array, convert it into a height-balanced binary search tree.




def getBinarySearchTree(arr, start, stop): 
    if start >= stop: 
        return

    mid = (start + stop)/2

    root = node(arr[mid])
    root.left = getBinarySearchTree(arr, start, mid)
    root.right = getBinarySearchTree(arr, mid+1, stop)

    return root

def constructTreeFromArray(arr): 
    if len(arr) == 0: 
        return None
    else if len(arr) == 1: 
        return node(arr[0])
    else: 
        return getBinarySearchTree(arr, 0, len(arr)-1)


