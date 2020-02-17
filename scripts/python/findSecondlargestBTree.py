class Node: 
    def __init__(self, key): 
        self.key = key
        self.left = None
        self.right = None


def findsecondLargestInBTree(root): 

    if root is None: 
        return None

    last_node = None
    current_Node = root 

    if root.right: 
        while(root.right): 
            last_node = current_Node
            current_Node = current_Node.right

        return last_node
    else: 
        current_Node = root.left
        while(current_Node.right): 
            current_Node = current_Node.right

        return current_Node

def test_1():
    node_a = Node(5)
    node_b = Node(3)
    node_c = Node(8)
    node_d = Node(2)
    node_e = Node(4)
    node_f = Node(7)
    node_g = Node(9)
    node_a.left = node_b
    node_a.right = node_c
    node_b.left = node_d
    node_b.right = node_e
    node_c.left = node_f
    node_c.right = node_g

    print(findsecondLargestInBTree(node_a).data)

test_1()
