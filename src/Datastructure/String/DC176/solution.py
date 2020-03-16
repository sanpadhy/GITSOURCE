
# Determine whether there exists a one-to-one character mapping from one string s1 to another s2.

# For example, given s1 = abc and s2 = bcd, return true since we can map a to b, b to c, and c to d.

# Given s1 = foo and s2 = bar, return false since the o cannot map to two characters.

def oneToOneMap(str1, str2): 
    charMap = dict()

    for c1, c2 in zip(str1, str2): 
        if c1 in charMap: 
            if charMap[c1] != c2: 
                return False
        else: 
            charMap[c1] = c2

    return True

print(oneToOneMap("abc", "bcd"))
