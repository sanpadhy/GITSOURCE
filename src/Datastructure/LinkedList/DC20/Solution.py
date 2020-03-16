# Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.

# For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

# In this example, assume nodes with the same value are the exact same node objects.

# Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.


class listNode:
    def __init__(self, key): 
        self.key = key
        self.next = None

def getIntersectPoint(root1, root2): 
    if not root1 or not root2: 
        return None

    p = root1
    q = root2

    while p or q: 
        p = p.next
        q = q.next

    return root1


node1 = listNode(3)
node2 = listNode(7)
node3 = listNode(8)
node4 = listNode(10)

node1.next = node2 
node2.next = node3 
node3.next = node4 

node5 = listNode(99)
node6 = listNode(1)
node7 = listNode(8)
node8 = listNode(10)

node5.next = node6
node6.next = node7
node7.next = node8 

print(getIntersectPoint(node1, node5))
