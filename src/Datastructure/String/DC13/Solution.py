# Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

# For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".


def findLongestSubstring(s, k): 
    if len(s) is 0 or s is None: 
        return ""

    if len(s) <= k: 
        return s

    if k is 1: 
        return s[0]

    secondcharIdx = 0
    firstChar = s[0]

    secondcharIdx = 0

    while s[secondcharIdx] == firstChar: 
        secondcharIdx += 1

    seenchars = set()
    count = 0
    candidate = None
    remainder = None

    i = 0
    for i, c in enumerate(s): 
        if c not in seenchars: 
            seenchars.add(c)
            count += 1

        if count > k: 
            candidate = s[:i]
            break
    
    print(candidate)
    remainder = findLongestSubstring(s[secondcharIdx:], k)
    print(remainder)

    if len(candidate) > len(remainder): 
        return candidate
    else: 
        return remainder

print(findLongestSubstring("aaabbbcba", 2))



