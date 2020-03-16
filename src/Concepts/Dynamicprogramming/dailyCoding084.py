def numIsland(grid): 
    if grid == 0 and len(grid) == 0: 
        return 0

    for i in range(len(grid)): 
        for j in range(len(grid[i])):
            print(grid[i][j])
       
    numIslands = 0
    
    for i in range(len(grid)): 
        for j in range(len(grid[i])):
            print(grid[i][j])
            if grid[i][j] == 1: 
                print(i, j)
                numIslands += dfsUtils(grid, i, j)
    
    return numIslands


def dfsUtils(grid, i, j): 
    if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[i]) or grid[i][j] == '0': 
        return 0
    
    grid[i][j] = '0'
    dfsUtils(grid, i+1, j)
    dfsUtils(grid, i-1, j)
    dfsUtils(grid, i, j+1)
    dfsUtils(grid, i, j-1)
    
    return 1


