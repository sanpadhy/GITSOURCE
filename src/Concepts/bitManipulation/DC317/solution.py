
# Write a function that returns the bitwise AND of all integers between M and N, inclusive.

# Logic: Linear way 

def findAndOfAllNum(start, end):
    if min == max: 
        return max

    result = max
    for var in range(start, end): 
        result = result & var

    return result

print(findAndOfAllNum(5, 6))

    


