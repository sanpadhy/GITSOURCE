# Given a sorted list of integers of length N, determine if an element x is in the list without 
# performing any multiplication, division, or bit-shift operations.

# Do this in O(log N) time.

import bisect

def getItemFromSortedList(arr, x): 
    pos = bisect.bisect(arr, x)
    return pos and arr[pos-1] == x

print(getItemFromSortedList([1, 3, 5, 7, 9], 6))

