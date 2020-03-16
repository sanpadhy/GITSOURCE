# Given a list of integers, return the largest product that can be made by multiplying any three integers.

# For example, if the list is [-10, -10, 5, 2], we should return 500, since that's -10 * -10 * 5.

# You can assume the list has at least three integers.

import sys

pairProduct = list()

def getPairProduct(arr): 
    for i in range(len(arr)): 
        for j in range(len(arr)): 
            if i != j: 
                pairProduct.append([set([i, j]), arr[i] * arr[j]])

    return pairProduct

def getMaxTripleMultiple(arr): 
    pairProduct = getPairProduct(arr)

    triplemax = 0 
    for i in range(len(arr)): 
        for pairIndex, product in pairProduct:
            if i not in pairIndex:
                if product * arr[i] > triplemax: 
                    triplemax = product * arr[i]
    
    return triplemax

arr = [-10, -10, 5, 2]
print(getMaxTripleMultiple(arr))

