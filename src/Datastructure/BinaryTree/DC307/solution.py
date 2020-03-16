import bisect

class Node: 
    def __init__(self, key): 
        self.key = key
        self.l = None 
        self.r = None

def get_list(root): 
    if not root: 
        return list()

    return get_list(root.l) + [root.key] + get_list(root.r)

def get_fc(root, var): 
    arr = get_list(root)

    ind = bisect.bisect(arr, var)
    print(ind)

    if ind == 0: 
        return (None, arr[0])
    elif ind == len(arr): 
        return (arr[-1], None)
    elif var == arr[ind]: 
        return (var, var) 
    else: 
        return (arr[ind-1], arr[ind])

a = Node(4)
b = Node(2)
c = Node(1)
d = Node(3)
b.l = c
b.r = d
e = Node(6)
a.l = b
a.r = e

# assert get_fc(a, 2) == (2, 2)
# print(get_fc(a, 7))
print(get_fc(a, -1))
print(get_fc(a, 5))
