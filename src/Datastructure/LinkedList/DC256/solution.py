# Given a linked list, rearrange the node values such that they appear in alternating low -> high -> low -> high ... form. 
# For example, given 1 -> 2 -> 3 -> 4 -> 5, you should return 1 -> 3 -> 2 -> 5 -> 4.

class node: 
    def __init__(self, key): 
        self.key = key
        self.next = None

def rearrangeNode(root): 
    if not root: 
        return None

    p = root.next

    while p: 
        if not p.next:
            break
            
        p.key, p.next.key = p.next.key, p.key
        p = p.next.next
            
    return root

def printList(root): 
    p = root
    while p: 
        print(p.key)
        p = p.next

n1 = node(1)
n2 = node(2)
n3 = node(3)
n4 = node(4)
n5 = node(5)

n1.next = n2 
n2.next = n3 
n3.next = n4 
n4.next = n5

printList(rearrangeNode(n1))









