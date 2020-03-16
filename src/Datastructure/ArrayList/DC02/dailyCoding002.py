# Two ways the problem can be solved. One using divisions and without using divisions.  

# Using division: 
# Take the cumulative products and the divide that with the actual var. 
# Cumulative products: 120 
# right_product_array --> [120.0, 60.0, 40.0, 30.0, 24.0]

def skipMultiplication_1(GivenList): 
    arr = [1, 2, 3, 4, 5]
    cumulative_product = 1
    right_prod_arr = list()

    for num in arr: 
        cumulative_product *= num
    
    for num in arr:    
        right_prod_arr.append(cumulative_product/num)
    
    return right_prod_arr    

# Without using division
# Take the cumulative product and append to list. list 1
# Reverse it, again take the cumulative product and append to list. List 2 
# Push 2nd from list 2 to final list
# For next 3 indexes [1, 2, 6] * [60, 20, 5]
# Push the 4th from list 1 to final list. 
#

def skipMultiplication_2(GivenList): 
    cummulation = 1
    rightData = list()
    
    for num in GivenList:
        cummulation *= num
        rightData.append(cummulation)
    
    cummulation = 1
    leftData = list()
    
    for num in GivenList[::-1]:
        cummulation *= num
        leftData.append(cummulation)
    
    leftData = leftData[::-1]
    
    resultList = list()
    
    for i in range(len(GivenList)):
        if i is 0: 
            num = leftData[i+1]
        elif i is len(GivenList)-1: 
            num = rightData[i-1]
        else: 
            num = leftData[i+1] * rightData[i-1]
        
        resultList.append(num)
    
    return resultList

print(skipMultiplication_1([1, 2, 3, 4, 5])) 
print(skipMultiplication_2([1, 2, 3, 4, 5])) 
    
