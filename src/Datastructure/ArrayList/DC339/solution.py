# Given an array of numbers and a number k, determine if there are three entries in the array which 
# add up to the specified number k. For example, given [20, 303, 3, 4, 25] and k = 49, return true as 20 + 4 + 25 = 49.

def get_twos_sum(result, arr):
    i, k = 0, len(arr) - 1
    while i < k:
        a, b = arr[i], arr[k]
        res = a + b
        if res == result:
            return (a, b)
        elif res < result:
            i += 1
        else:
            k -= 1


def get_threes_sum(result, arr):
    arr.sort()
    for i in range(len(arr)):
        c = arr[i]
        if c > result:
            continue
        twos = get_twos_sum(result - c, arr[:i] + arr[i+1:])
        if twos:
            return True

    return get_twos_sum(result, arr)


# Tests
assert get_threes_sum(49, [20, 303, 3, 4, 25])
assert not get_threes_sum(50, [20, 303, 3, 4, 25])
