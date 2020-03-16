# Given an array and a number k that's smaller than the length of the array, rotate the array to the right k elements in-place.

def rotate_num(arr, k, srcidx, srcnum, count=0): 
    if count == len(arr): 
        return

    destidx = (srcidx + k)%len(arr)
    destnum = arr[destidx]

    arr[destidx] = srcnum

    rotate_num(arr, k, destidx, destnum, count+1)

def rotatenum(arr, k): 
    rotate_num(arr, k, 0, arr[0])

print(rotatenum([1, 2, 3, 4, 5], 2))
