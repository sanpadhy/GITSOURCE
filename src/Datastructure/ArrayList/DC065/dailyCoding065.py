def get_spiral(matrix, srow, scol, erow, ecol):
    numbers = list()
    for i in range(scol, ecol + 1):
        numbers.append(matrix[srow][i])

    for i in range(srow + 1, erow + 1):
        numbers.append(matrix[i][ecol])

    if srow < erow:
        for i in range(ecol - 1, srow - 1, -1):
            numbers.append(matrix[erow][i])

    if scol < ecol:
        for i in range(erow - 1, srow, -1):
            numbers.append(matrix[i][scol])

    return numbers


def spiral_helper(matrix):
    srow, scol, erow, ecol = 0, 0, len(matrix) - 1, len(matrix[0]) - 1
    clockwise_numbers = list()
    while srow < erow or scol < ecol:
        clockwise_numbers.extend(get_spiral(matrix, srow, scol, erow, ecol))
        if srow < erow:
            srow += 1
            erow -= 1
        if scol < ecol:
            scol += 1
            ecol -= 1

    return clockwise_numbers


matrix_0 = [[1,  2,  3,  4,  5],
            [6,  7,  8,  9,  10],
            [11, 12, 13, 14, 15],
            [16, 17, 18, 19, 20]]

print(spiral_helper(matrix_0))
