# Implement a stack that has the following methods:

#    push(val), which pushes an element onto the stack
#    pop(), which pops off and returns the topmost element of the stack. If there are no elements in the stack, then it should throw an error or return null.
#    max(), which returns the maximum value in the stack currently. If there are no elements in the stack, then it should throw an error or return null.

# Each method should run in constant time.


def getSubarrayWithSum(arr, sum): 
    result = list()
    
    if len(arr) == 0: 
        return None

    if sum <= 0: 
        return None

    if sum == arr[0]: 
        return [arr[0]]

    subset = getSubarrayWithSum(arr[1:], sum-arr[0])

    if subset: 
        return [arr[0]] + subset
    else: 
        return getSubarrayWithSum(arr[1:], sum)
    
S = [12, 1, 61, 5, 9, 2]

print(getSubarrayWithSum(S, 24))
