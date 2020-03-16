import numpy as np 

def get_matrix_traversals(row, col): 
    i, j = 0, 0
    
    t = np.zeros((row, col))
        
    for i in range(row): 
        for j in range(col): 
            if i is 0 or j is 0: 
                t[i][j] = 1
            else:
                t[i][j] = t[i-1][j] + t[i][j-1]
                
    return t[i][j]

print(get_matrix_traversals(1, 1))
print(get_matrix_traversals(2, 2))
print(get_matrix_traversals(5, 5))
