# Given an integer n, return the length of the longest consecutive run of 1s in its binary representation.

# For example, given 156, you should return 3.

# 10011100


def getLongestOnesequence(num): 
    str_bin = str(bin(num))
    
    start = 0
    last = 0
    longest = 0
    flag = False

    for i, c in enumerate(str_bin[2:]): 
        if c == '1': 
            if flag == False: 
                start = i
                flag = True
        else: 
            if flag == True: 
                length = i - start
                flag = False 
                start = 0
                print(length)
                if length > longest: 
                    longest = length
    
    return longest

print(getLongestOnesequence(21))
