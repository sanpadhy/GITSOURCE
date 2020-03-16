def longestIncreasing(arr): 
    if len(arr) <= 1: 
        return len(arr)

    start = 0
    end = 0
    longest = list()

    for i in range(len(arr)): 
        if arr[i] < arr[i-1]: 
            start = i
            continue
        end = i+1 

        if end-start > len(longest):
            longest = arr[start:end]


    return longest

print(longestIncreasing([1, 2, 3, 5, 4]))

        
