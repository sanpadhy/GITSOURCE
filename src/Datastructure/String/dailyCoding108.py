def can_shift(target, string):
    return \
        target and string and \
        len(target) == len(string) and \
        string in target * 2


print(can_shift("abcde", "cdeab"))
print(can_shift("abc", "acb"))
