# Two nodes in a binary tree can be called cousins if they are on the same level of the tree but have different parents. For example, in the following diagram 4 and 6 are cousins.

#     1
#    / \
#   2   3
#  / \   \
# 4   5   6

# Given a binary tree and a particular node, find all cousins of that node.

# Logic: 
# Created a noteMap dictionary in which level is the key and node are the values. 
# The nodemap has been populated and later parsed through to find the nodes cousin 
# In every level.  


class node: 
    def __init__(self, key): 
        self.key = key
        self.left = None
        self.right = None
    

def populateNodeMap(node, nodeMap, parent=None, lavel = 0): 
    if not node: 
        return None

    node.p = parent
    node.lev = level

    if level not in nodeMap: 
        nodeMap[level] = set()

    nodeMap[level].add(node)

    populateNodeMap(node.left, nodeMap, node, level+1)
    populateNodeMap(node.right, nodeMap, node, level+1)


def cousinsInBinaryTree(root, level=0): 
    if not root: 
        return None

    nodeMap = dict()

    populateNodeMap(root, nodeMap)

    cousin = set([x for x in nodeMap[root.key] if x.p != root.p]) 

    return cousin



