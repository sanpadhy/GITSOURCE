# You are given a histogram consisting of rectangles of different heights. These heights are represented 
# in an input list, such that [1, 3, 2, 5] corresponds to the following diagram:

#       x
#       x  
#   x   x
#   x x x
# x x x x

# Determine the area of the largest rectangle that can be formed only from the bars of the histogram. 
# For the diagram above, for example, this would be six, representing the 2 x 3 area at the bottom right.

def get_max_hist_area(arr, start, end):
    if start == end:
        return 0

    curr_area = (end - start) * min(arr[start:end])
    opt_1 = get_max_hist_area(arr, start, end - 1)
    opt_2 = get_max_hist_area(arr, start + 1, end)

    return max(curr_area, opt_1, opt_2)


def get_max_hist_area_helper(arr):
    return get_max_hist_area(arr, 0, len(arr))


# Tests
assert get_max_hist_area_helper([1, 3, 2, 5]) == 6
