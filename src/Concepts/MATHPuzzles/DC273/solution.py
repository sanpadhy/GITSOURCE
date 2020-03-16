def getFixedPoint(arr): 
    for i, v in enumerate(arr): 
        if i == v: 
            return i

    return False

print(getFixedPoint([1, 5, 7, 8]))
