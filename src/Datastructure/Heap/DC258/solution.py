from heapq import heappush as hp

def findSmallestWindowsForSort(arr): 
    if arr == sorted(arr): 
        return ()

    options = list()
    for sort_start in range(len(arr)-1): 
        for sort_end in range(1, len(arr)): 
            a1 = arr[:sort_start]
            a2 = sorted(arr[sort_start:sort_end])
            a3 = arr[sort_end:]

            new_arr = a1 + a2 + a3

            if new_arr == sorted(arr): 
                hp(options, (sort_end-sort_start, (sort_start, sort_end-1)))
    
    return options[0][1]

arr = [1, 2, 5, 3, 4, 6]
print(findSmallestWindowsForSort(arr))
