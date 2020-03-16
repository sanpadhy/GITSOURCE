# Given a string, split it into as few strings as possible such that each string is a palindrome.

# For example, given the input string "racecarannakayak", return ["racecar", "anna", "kayak"].

# Given the input string "abc", return ["a", "b", "c"].

def splitStringIntoPalindrom(s): 
    palindroms = list()

    i = 0
    while i < len(s): 
        firstChar = s[i]
        
        print(firstChar)

        for i, c in enumerate(s[1:]): 
            if c == firstChar:
                palindroms.append(s[:i]+c)
                i = i+1
                print(palindroms)
                print(i)
                break 


s = "racecarannakayak"
print(splitStringIntoPalindrom(s))

