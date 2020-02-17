import json

class BTree: 
    def __init__(self, key): 
        self.key = key
        self.left = None
        self.right = None


def serialize(root):
    if root == None: 
        return None

    Tree_map = dict()

    treeLeft = serialize(root.left)
    treeRight = serialize(root.right)

    if root.key: 
        Tree_map['root'] = root.key
    if treeLeft: 
        Tree_map['left'] = treeLeft
    if treeRight: 
        Tree_map['right'] = treeRight
    
    return json.dumps(Tree_map)

def deserialize(s): 

    tree_Map = dict()

    tree_Map = json.loads(s)

    if "root" in tree_Map: 
        root.key = tree_Map["root"]

    if "left" in tree_Map:
        root.left = tree_Map["left"]
        
    if "right" in tree_Map:
        root.left = tree_Map["right"]

    return root

root = None    
root = BTree(12)
node1 = BTree(14)
node2 = BTree(10)
root.right = node1
root.left = node2

s = serialize(root)

print(s)

root = deserialize(s)

