class Node: 
    def __init__(self, key): 
        self.key = key
        self.left = None 
        self.right = None


def GetMathematicalExpression(root): 
    if root.key.isnumeric(): 
        return float(root.key)

    return eval("{} {} {}" .format(GetMathematicalExpression(root.left), root.key, GetMathematicalExpression(root.right)))


d = Node("3")
e = Node("2")
f = Node("4")
g = Node("5")

b = Node("+")
b.left = d
b.right = e

c = Node("+")
c.left = f
c.right = g

a = Node("*")
a.left = b
a.right = c


print(GetMathematicalExpression(a))
