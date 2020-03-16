# Potential solution is the set where you traverse the array and store the value. 
# with every traversal find whether the differential is part of this thread. 
#  1) potential_solution --> Empty
#     num --> 1  temp --> 15 
#     whether 15 part of set potential_solutions No
#     Add 1 to potential_solutions 
#  .........
#  5) potential_solution --> 1, 4, 45, 6
#     num --> 10  temp --> 6 
#     whether 6 part of set potential_solutions Yes
#     Pair --> num & temp 
#  

def printPairs(arr, arr_size, k):
    potential_solutions = set()
    
    for num in arr:
        temp = k-num 
        if num in potential_solutions:
            print('pair of numbers', num, "and", temp)
            return True 

        potential_solutions.add(temp)

    return False


A = [1,4,45,6,10,8]
n = 16
printPairs(A, len(A), n)


