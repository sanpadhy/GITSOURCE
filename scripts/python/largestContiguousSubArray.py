
def largestContiguousSubarray(arr):
    current = arr[0]
    largest = arr[0]

    for var in arr[1:]: 
        current = max(current+var, var)
        largest = max(current, largest)

    return largest

print(largestContiguousSubarray([34, -50, 42, 14, -5, 86]))
