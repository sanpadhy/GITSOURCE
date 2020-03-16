# Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
# Find the minimum element in O(log N) time. You may assume the array does not contain duplicates.

# For example, given [5, 7, 10, 13, 4], return 3.

def searchItem(arr, start, end, var): 
    mid = 0
    while start < end: 
        mid = (start+end)//2
        print(arr[mid])
        print(arr[start])
        print(arr[end])
        if var == arr[mid]: 
            return mid
        elif var < arr[mid]: 
            if var < arr[start]: 
                start = mid+1
            else: 
                end = mid-1
        else: 
            if var > arr[end]: 
                start = mid+1
            else: 
                end = mid-1
    
    return -1

def searchItemFromUnsorted(arr, var): 
    return searchItem(arr, 0, len(arr)-1, var) 

arr = [5, 7, 10, 3, 4]
print(searchItemFromUnsorted(arr, 3))
