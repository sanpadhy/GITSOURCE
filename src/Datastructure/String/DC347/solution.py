# You are given a string of length N and a parameter k. The string can be manipulated by taking one of the first k letters and moving it to the end.

# Write a program to determine the lexicographically smallest string that can be created after an unlimited number of moves.

# For example, suppose we are given the string daily and k = 1. The best we can create in this case is ailyd.

def lex_mod(string, k):
    if k > 1:
        return "".join(sorted(string))

    min_ch = min(string)
    joined = string + string
    for i, ch in enumerate(joined):
        if ch == min_ch:
            return joined[i:i + len(string)]


# Tests
assert lex_mod("daily", 2) == "adily"
assert lex_mod("daily", 1) == "ailyd"
