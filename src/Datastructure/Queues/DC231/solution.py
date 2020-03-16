
# Given a string with repeated characters, rearrange the string so that no two adjacent 
# characters are the same. If this is not possible, return None.

# For example, given "aaabbc", you could return "ababac". Given "aaab", return None.

from collections import Counter
from queue import Queue

def reorganizeChar(st): 
    charMap = Counter(st)

    sitems = sorted(charMap.items(), key = lambda x: x[1], reverse=True)

    # Check for the length of the string with the length of higher char count. 
    # If highest char count is more then half of length of string, return None 

    if sitems[0][1] > len(st)//2: 
        return None

    q = Queue()
    for item in sitems: 
        q.put(item)

    new_str = ""

    while not q.empty():
        item = q.get()
        new_str += item[0]
        # new_str will be added with the character from item[0] 
        print(new_str)
        # Item[0] is the character i.e. a in (a, 3)
        print(item[0])

        # (The below string would be (a, 2))
        item = (item[0], item[1] - 1)
        if(item[1]): 
            q.put(item)

    return new_str

print(reorganizeChar("bbaaac"))
