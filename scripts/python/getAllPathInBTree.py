class Node:
    def __init__(self, key): 
        self.key = key
        self.left = None
        self.right = None

def getAllPaths(root): 
    if root is None: 
        return []

    paths = list()

    leftpaths = getAllPaths(root.left)

    for leftpath in leftpaths:
        paths.append([root.key]+leftpath)

    rightpaths = getAllPaths(root.right)

    for rightPath in rightpaths: 
        paths.append([root.key]+rightpaths)

    return paths if paths else [[root.key]]


a = Node(1)
b = Node(2)
c = Node(3)
d = Node(4)
e = Node(5)

a.left = b
a.right = c
c.left = d
c.right = e

print(getAllPaths(a))

