# Write a program to merge two binary trees. Each node in the new tree should hold a value equal to the sum of the values of the corresponding nodes of the input trees.

# If only one input tree has a node in a given position, the corresponding node in the new tree should match that input node.

class Node:
    def __init__(self, val):
        self.val = val
        self.l = None
        self.r = None

    def __repr__(self):
        return "{}".format(self.val)

def merge(t1, t2, final_prev, left): 
    if not t1 and not t2: 
        return None

    if t1 and t2: 
        final_tree= Node(t1.val + t2.val)

        if left:
            final_prev.l = final_tree
        else: 
            final_prev.r = final_tree 

        merge(t1.l, t2.l, final_tree, True)
        merge(t2.r, t2.r, final_tree, False)
        return

        remain_node = t1 if t1 else t2

        if left: 
            final_prev.l = remain_node
        else: 
            final_prev.r = remain_node


# Tests
root_1 = Node(1)
root_1.l = Node(2)
root_1.r = Node(3)
root_1.l.l = Node(4)

root_2 = Node(2)

final_root = Node(0)
merge(root_1, root_2, final_root, True)
print(final_root.l.val)
