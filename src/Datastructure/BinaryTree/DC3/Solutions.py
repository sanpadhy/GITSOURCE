# Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.

import json 

class node: 
    def __init__(self, key): 
        self.key = key
        self.left = None
        self.right = None

    def serialize(self, root): 
        if not root: 
            return ""

        if self.root.left: 
            leftNode = serialize(self, self.root.left)

        if self.root.right: 
            rightNode = serialize(self, self.root.right)

        treemap = dict()

        treemap['root'] = self.root.key

        if leftNode: 
            treemap['left'] = leftNode

        if rightNode: 
            treemap['right'] = rightNode

        return json.dumps(treemap)

    def deserialize(s): 
        treemap = dict()

        treemap = json.loads(s)

        node1 = node(treemap['root'])
        
        if 'left' in treemap: 
            node1.left = deserialize(treemap['left'])
        if 'right' in treemap: 
            node1.right = deserialize(treemap['right'])

        return node1


node1 = node(23)
node2 = node(45)
node3 = node(51)
node4 = node(67)

node1.left = node2
node1.right = node3
node2.left = node4

print(node1.serialize(root))

