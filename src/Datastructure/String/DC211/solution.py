# Given a string and a pattern, find the starting indices of all occurrences of the pattern in the string. 
# For example, given the string "abracadabra" and the pattern "abr", you should return [0, 7].


def findAllOccOfPattern(st, pat): 
    result = list()
    lst = len(st)
    lpat = len(pat)

    for c in range(0, lst-lpat): 
        if st[c:c+lpat] == pat: 
            result.append(c)

    return result


pattern = "abr" 
string = "abracadabra"
print(findAllOccOfPattern(string, pattern))







