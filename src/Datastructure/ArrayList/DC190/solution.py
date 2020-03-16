# Given a circular array, compute its maximum subarray sum in O(n) time.

# For example, given [8, -1, 3, 4], return 15 as we choose the numbers 3, 4, and 8 where the 8 is obtained from wrapping around.

# Given [-4, 5, 1, 0], return 6 as we choose the numbers 5 and 1.

def maximumSubarrayInCArray(arr): 
    if len(arr) == 0: 
        return None

    warr = arr * 2
    cList = list()
    result = list()
    csum = 0
    msum = 0

    for num in warr: 
        while len(cList) >= len(arr) or (cList and cList[0] < 0): 
            csum -= cList[0]
            cList = cList[1:]

        csum += num
        cList.append(num)

        if csum > msum:
            msum = csum
            result.append(num)

    print(result)
        
arr = [-4, 5, 1, 0]
print(maximumSubarrayInCArray(arr))


