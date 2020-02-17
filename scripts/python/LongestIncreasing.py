
def longestIncreasingSubsequence(arr): 
    result = [1, 1, 1, 1, 1]
    incrSequence = list()

    
    i = 1
    while(i < len(arr)):
        j = 0
        while(j < i): 
            if(arr[i] > arr[j]):
                if((result[j] + 1) > (result[i])): 
                    result[i] = result[j]+1
            j += 1

        i += 1

    print(result[4])

    i = len(result)-1
    while(i):
        if(result[i] > result[i-1]): 
            incrSequence.append(arr[i]) 
        i -= 1

    incrSequence.append(arr[i])
    print(incrSequence[::-1])

longestIncreasingSubsequence([5, 4, 3, 2, 1])

