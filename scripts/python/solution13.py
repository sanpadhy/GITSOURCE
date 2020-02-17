class list: 
    def __init__(self, key): 
        self.key = key
        self.next = None

def removeKthElement(head, k):
    if head == None or k == 0: 
        return None

    fast = head
    second = head
    temp = None

    for _ in range(k): 
        fast = fast.next

    while fast: 
        fast = fast.next 
        temp = second
        second = second.next

    temp.next = second.next

    return head

L1 = list(12)
L2 = list(15)
L3 = list(16)
L4 = list(17)

L1.next = L2
L2.next = L3 
L3.next = L4

L1 = removeKthElement(L1, 3)
print(L1)

