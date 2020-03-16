# Given an array of numbers, find the maximum sum of any contiguous subarray of the array.

# For example, given the array [34, -50, 42, 14, -5, 86], the maximum sum would be 137, since we would take elements 42, 14, -5, and 86.

# Given the array [-5, -1, -8, -9], the maximum sum would be 0, since we would not take any elements.

# Do this in O(N) time.

def getLargestContiguous(arr): 
    current = arr[0]
    largest = arr[0]

    for var in arr[1:]: 
        current = max(current+var, var)
        print(current)
        largest = max(largest, current)
        print(largest)

    return largest


arr = [34, -50, 42, 14, -5, 86]

print(getLargestContiguous(arr))
