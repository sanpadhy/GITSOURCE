def partitionArrayWithEqualSum(arr, start, end, outerSum, innerSum):
    if(start >= end):
        return False
    if (innerSum == outerSum): 
        return True

    return (partitionArrayWithEqualSum(arr, start+1, end, outerSum+arr[start], innerSum-arr[start]) \
            or partitionArrayWithEqualSum(arr, start, end-1, outerSum+arr[end], innerSum-arr[end]))


def partitionArray(arr): 
    if arr is None: 
        return True

    totalsum = 0

    for var in arr: 
        totalsum += var

    if(totalsum%2 == 1): 
        return False

    arr.sort()

    return partitionArrayWithEqualSum(arr, 0, len(arr)-1, 0, totalsum)

print(partitionArray([15, 5, 20, 10, 35, 15, 10, 110]))


