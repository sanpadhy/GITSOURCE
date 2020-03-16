def isPowerofFour(x): 
    return ((x & -x) & 0x555555540) == x

print(isPowerofFour(128))
