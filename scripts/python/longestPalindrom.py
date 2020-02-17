def isPalindrom(s): 
    return 1 if s == s[::-1] else 0

def longestPalindrom(s): 
    if s == None or isPalindrom(s): 
        return s

    s1 = longestPalindrom(s[1:])
    s2 = longestPalindrom(s[:-1])

    if(len(s1) > len(s2)): 
        return s1
    else: 
        return s2

print(longestPalindrom("aabcdcb"))


