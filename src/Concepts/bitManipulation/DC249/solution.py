# Given an array of integers, find the maximum XOR of any two elements.

def findMaxXorOfNum(arr):
    if len(arr) == 0: 
        return 0

    xored = 0
    for v in arr: 
        for w in arr[1:]:
            xored = max(xored, v ^ w)
    
    return xored

print(findMaxXorOfNum([1, 2, 3, 4]))

