def findpartitionwithsum(arr, k): 
    if k == 1: 
        return arr

    sumArray = sum(arr)
    div = sumArray/k 

    currentsum = 0
    start = 0
    minval = 0
    result = list()

    for i in range(len(arr)): 
        currentsum += arr[i]
        if currentsum > div: 
            result.append(arr[start, i-1])
            start = i
            varsum = 0
            

    return result

print(findpartitionwithsum([5, 1, 2, 7, 3, 4], 3))
