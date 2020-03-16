# Find the maximum of two numbers without using any if-else statements, branching, or direct comparisons.

def getMaximumOfTwo(a, b): 
    c = a - b           # you can have positive or negative 
    k = (c >> 31) & 1   # check for whether the last bit is 1 or 0. 

    return a - (c * k)  

print(getMaximumOfTwo(10, 15))



