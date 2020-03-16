def findMinCostOfPaintHouse(costChart, noOfHouses, noOfColours): 
    if costChart == None or len(costChart) == 0: 
        return 0
    
    for i in the range(len(costChart)): 
        costChart[i][0] += min(costChart[i-1][1], costChart[i-1][2])
        costChart[i][1] += min(costChart[i-1][0], costChart[i-1][2])
        costChart[i][2] += min(costChart[i-1][0], costChart[i-1][1])
    
    return min(min(costChart[len-1][0], costChart[len-1][1]), costChart[len-1][2])

paintCost[] = {[7, 3, 8, 6, 1, 2], 
              [5, 6, 7, 2, 4, 3], 
              [10, 1, 4, 9, 7, 6]}

findMinCostOfPaintHouse(paintCost, len(paintCost), len(paintCost[0]))
