# Given a linked list and a positive integer k, rotate the list to the right by k places.

# For example, given the linked list 7 -> 7 -> 3 -> 5 and k = 2, it should become 3 -> 5 -> 7 -> 7.

# Given the linked list 1 -> 2 -> 3 -> 4 -> 5 and k = 3, it should become 3 -> 4 -> 5 -> 1 -> 2.

class node: 
    def __init__(self, key): 
        self.key = key
        self.next = None

def findLength(root):
    if not root:
        print("Empty List")
        return 0

    p = root
    count = 0

    while(p): 
        count += 1
        p = p.next

    return count

def printList(root): 
    p = root

    while p: 
        print(p.key)
        print("->")
        p = p.next

def rotateListByk(root, k):
    length = findLength(root)
    if length <= k: 
        return root
    
    p = root
    q = None

    while k:
        q = p
        p = p.next
        k -= 1

    q.next = None
    newRoot = p

    while(p):
        q = p
        p = p.next
    
    q.next = root 
    
    return newRoot  

n1 = node(1)
n2 = node(2)
n3 = node(3)
n4 = node(4)
n5 = node(5)

n1.next = n2
n2.next = n3 
n3.next = n4
n4.next = n5

n = None

newRoot = rotateListByk(n, 2)
printList(newRoot)


