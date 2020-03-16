# Write a function that rotates a list by k elements. For example, [1, 2, 3, 4, 5, 6] 
# rotated by two becomes [3, 4, 5, 6, 1, 2]. Try solving this without creating a copy of the list. How many swap or move operations do you need?

def rotatebyonce(arr): 
    first = arr[0]
    for i in range(len(arr)-1): 
        arr[i], arr[i+1] = arr[i+1], arr[i]

    arr[-1] = first
    return arr


def rotateByk(arr, k): 
    for i in range(k): 
        arr = rotatebyonce(arr)

    return arr


if __name__== "__main__":
    arr = [1, 2, 3, 4, 5, 6]
    print(rotateByk(arr, 2))
