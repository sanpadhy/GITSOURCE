# Given a string, find the length of the smallest window that contains every distinct character. Characters may appear more than once in the window.

# For example, given "jiujitsu", you should return 5, corresponding to the final five letters.

def getSmallestWindowUniqueChar(s, start, end, unique_char_count): 
    substring = s[start:end]
    if start == end or len(substring) < unique_char_count:
        return len(substring)

    can1 = getSmallestWindowUniqueChar(s, start, end-1, unique_char_count)
    can2 = getSmallestWindowUniqueChar(s, start+1, end, unique_char_count)

    return min(len(substring), min(can1, can2))

def getSmallestWindow(s): 
    if len(s) <= 1:
        return s

    seenChars = set()
    count = 1

    for c in s: 
        if c not in seenChars: 
            seenChars.add(c)
            count += 1

    print(seenChars, count)

    if len(s) == count: 
        return s

    return getSmallestWindowUniqueChar(s, 0, len(s), count)


print(getSmallestWindow("jiujitsu"))


