# Let's represent an integer in a linked list format by having each node represent a digit in the number. The nodes make up the number in reversed order.

# For example, the following linked list:

# 1 -> 2 -> 3 -> 4 -> 5 is the number 54321.

# Given two linked lists in this format, return their sum in the same linked list format.

# For example, given

# 9 -> 9 5 -> 2 return 124 (99 + 25) as:

# 4 -> 2 -> 1

class node: 
    def __init__(self, key): 
        self.key = key
        self.next = None

def reverse(root):
    p = root
    q = None
    r = p.next

    while r:
        p.next = q
        q = p
        p = r 
        r = r.next
    
    p.next = q
    return p


def addTwoListInReverseOrder(root1, root2): 
    if not root1 and not root2: 
        return None

    if not root1 and root2: 
        return root2 

    if not root2 and root1: 
        return root1

    p = reverse(root1) 
    q = reverse(root2)

    multi = 0

    while p:
        multi = multi * 10 + p.key
        p = p.next 

    num1 = multi

    multi = 0
    while q: 
        multi = multi * 10 + q.key
        q = q.next

    num2 = multi

    result = num1 + num2 
    print(result)

    root = None
    while(result): 
        remainder = result % 10
        result /= 10 
        n1 = node(remainder)
        n1.next = root
        root = n1
    
    root = reverse(root)

    p = root
    while(p): 
        print(p.key)
        p = p.next

    return root

n1 = node(9)
n2 = node(9)

n1.next = n2 

n3 = node(5)
n4 = node(2)

n3.next = n4 

print(addTwoListInReverseOrder(n1, n3))



