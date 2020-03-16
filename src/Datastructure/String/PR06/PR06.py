# Implement an algorithm to determine if a string has all unique characters. What if you
# cannot use additional data structures?

# Ask whether the string is ASCI string or Unicode string. Unicode string mean will need More storage space. 
# Major Pointers: 
#      128 Character alphabets 
#      256 for extended ASCI 

# Solution 1: Create a array of boolean vector. where the flag at index i indicates whether character
# i in the alphabet is contained in the string.

# The second time you see this character you can immediately return false.
# Inefficient in the form of space. 

# Solution 2: 
# To reduce the space usage by a factor of eight by using a bit vector.

# Time complexity -- O(n)

import numpy

def HavingUniqueCharacter(s): 
    if len(s) > 128: 
        return False

    n = 128
    charSet = numpy.empty(n, dtype=bool)

    for v in s: 
#        if charSet[v]: 
#            return False
        print(charSet[v])

    return True

print(HavingUniqueCharacter("hjhjkhjhulgydrdseaerjkghksjkghk"))
