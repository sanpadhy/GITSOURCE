def findLargestNonAdj(arr): 
    previous = 0
    current = 0

    for var in arr: 
        previous, current = current, max(previous+var, current) 


    return current

print(findLargestNonAdj([2, 4, 6, 8]))

