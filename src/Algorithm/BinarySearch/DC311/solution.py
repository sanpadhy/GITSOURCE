# Given an unsorted array, in which all elements are distinct, find a "peak" element in O(log N) time.

# An element is considered a peak if it is greater than both its left and right neighbors. It is guaranteed that the first and last elements are lower than all others.


# Logic: Time complexity: O(log N) means binary Search 


def findPeak(arr): 
    if len(arr) == 0: 
        return 0

    mid = len(arr)//2

    if mid > 0 and arr[mid] > arr[mid-1] and mid < len(arr) and arr[mid] > arr[mid+1]: 
        return arr[mid]

    if mid > 0 and arr[mid] > arr[mid-1]:
        return findPeak(arr[:mid])
    else: 
        return findPeak(arr[mid+1:])


print(findPeak([0, 2, 4, 5, 3, 1]))
        


