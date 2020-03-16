# Refer the protocol buffer being written by google.  

import json

# Serialization is a process of converting an object into a sequence of bytes which can be persisted to a disk or database or 
# can be sent through streams IN THE NETWORK. The reverse process of creating object from sequence of bytes is called 
# deserialization.

class treeNode: 
    def __init__(self, key): 
        self.key = key
        self.left = None
        self.right = None 
    
    def __repr__(self): 
        return str(self.key)
    
def serialize(root):
    if not root: 
        return None
    
    DataMap = dict()
    
    DataMap['data'] = root.key
    
    if root.left: 
        LeftNode = serialize(root.left)
        DataMap['left'] = LeftNode
    if root.right: 
        RightNode = serialize(root.right)
        DataMap['right'] = RightNode 

    # JSON is a syntax for storing and exchanging data.

    # JSON is text, written with JavaScript object notation.        
        
    # convert any python object to json string 
    
    return json.dumps(DataMap)

def deserialize(s): 
    DataMap = dict()
    
    # If you have a JSON string, you can parse it by using the json.loads() method.
    # The result is in Python dictionary 
    
    DataMap = json.loads(s)
    
    root = treeNode(DataMap['data'])
    
    if 'left' in DataMap: 
        leftChild = DataMap['left']
        root.left = leftChild
    if 'right' in DataMap: 
        rightChild = DataMap['right']
        root.right = rightChild
    
    return root

# Building the tree of characters. 
node_a = treeNode('a')
node_b = treeNode('b')
node_c = treeNode('c')
node_d = treeNode('d')
node_e = treeNode('e')
node_f = treeNode('f')
node_g = treeNode('g')
node_a.left = node_b
node_a.right = node_c
node_b.left = node_d
node_b.right = node_e
node_c.left = node_f
node_c.right = node_g
#####

# Serialize the tree into string 
serialized_a = serialize(node_a)
print(serialized_a)

# Deserialize the string into tree 
deserialized_a = deserialize(serialized_a)
print(deserialized_a)
    
