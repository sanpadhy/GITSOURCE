def getSquareInSortedForm(arr): 
    sortedSquare = list()

    for var in arr: 
        square = var**2
        print(square)
        sortedSquare.append(square)

    sortedSquare.sort()
    
    return sortedSquare

print(getSquareInSortedForm([-9, -2, 0, 2, 3]))


