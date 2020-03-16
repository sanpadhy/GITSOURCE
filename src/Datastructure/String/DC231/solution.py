# Given a string with repeated characters, rearrange the string so that no two adjacent characters are the same. If this is not possible, return None.

# For example, given "aaabbc", you could return "ababac". Given "aaab", return None.

from collections import Counter
from queue import Queue


def rearrange(string):
    c = Counter(string)
    sitems = sorted(c.items(), key=lambda x: x[1], reverse=True)

    strlen = len(string)
    if strlen % 2:
        if sitems[0][1] > (strlen // 2) + 1:
            return None
    else:
        if sitems[0][1] > (strlen // 2):
            return None

    q = Queue()
    for item in sitems:
        q.put(item)

    new_str = ""
    while not q.empty():
        item = q.get()
        print(item)
        new_str += item[0]
        item = (item[0], item[1] - 1)
        print(item)
        if item[1]:
            q.put(item)

    return new_str


# Tests
assert rearrange("aaabbc") == "abcabaa"
assert rearrange("aaab") == None
