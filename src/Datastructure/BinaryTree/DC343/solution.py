# Given a binary search tree and a range [a, b] (inclusive), return the sum of the elements of the binary search tree within the range.

# For example, given the following tree:

#     5
#    / \
#   3   8
#  / \ / \
# 2  4 6  10

# and the range [4, 9], return 23 (5 + 4 + 6 + 8).

class Node:
    def __init__(self, val):
        self.val = val
        self.l = None
        self.r = None


def sum_range(node, lo, hi):
    if not node:
        return 0
    elif node.val < lo:
        return sum_range(node.r, lo, hi)
    elif node.val > hi:
        return sum_range(node.l, lo, hi)

    return node.val + sum_range(node.l, lo, hi) + sum_range(node.r, lo, hi)


# Tests
a = Node(5)
b = Node(3)
c = Node(8)
d = Node(2)
e = Node(4)
f = Node(6)
g = Node(10)
a.l = b
a.r = c
b.l = d
b.r = e
c.l = f
c.r = g
assert sum_range(a, 4, 9) == 23
