

# Given an array of positive integers, divide the array into two subsets such that the 
# difference between the sum of the subsets is as small as possible.

# For example, given [5, 10, 15, 20, 25], return the sets {10, 25} and {5, 15, 20}, which 
# has a difference of 5, which is the smallest possible difference.

def findNuminDiff(arr1, sumArr1, arr2, sumArr2, score): 

    for i, var in enumerate(arr): 
        newsumArr1, newsumArr2 = sumArr1-arr1[0], sumArr2+arr1[0]
        newScore = abs(newsumArr1-newsumArr2)



def findNumsWithMinDifference(arr): 
    totalsum = sum(arr)

    print(totalsum)

    return arr


arr = [5, 10, 15, 20, 25]
print(findNumsWithMinDifference(arr))



