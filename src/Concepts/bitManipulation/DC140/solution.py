# Given an array of integers in which two elements appear exactly once and all other elements appear exactly twice, find the two elements that appear only once.

# For example, given the array [2, 4, 6, 8, 10, 2, 6, 10], return 4 and 8. The order does not matter.

# Follow-up: Can you do this in linear time and constant space?

def findNonRepeatNum(arr):
    xored = 0
    rightMostSetBit = 0

    for var in arr: 
        xored ^= var 
    
    x, y = 0, 0
    rightMostSetBit = xored & ~(xored-1)

    for var in arr: 
        if var & rightMostSetBit: 
            x ^= var
        else: 
            y ^= var

    return (x, y)


arr = [2, 4, 6, 8, 10, 2, 6, 10]
print(findNonRepeatNum(arr))
