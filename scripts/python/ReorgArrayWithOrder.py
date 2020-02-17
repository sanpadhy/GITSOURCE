
def swap(arr, i, j):
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp
    


def reorder_array(arr): 
    last_index = reorderArrayWithIndex(arr, 0, len(arr)-1, 'R')
    reorderArrayWithIndex(arr, last_index+1, len(arr)-1, 'G')
    return arr


def reorderArrayWithIndex(arr, start, last, letter): 
    i = start
    j = last 
    lastindex = 0

    while (i < j) : 
        if(arr[i] == letter): 
            i += 1
        elif(arr[j] != letter): 
            j -= 1
        else: 
            lastIndex = i
            swap(arr, i, j)

    return lastindex


print(reorder_array(['G', 'R']))

