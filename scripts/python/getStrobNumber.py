def getStrobNumber(count): 
    if count is 0:
        return [""]
    elif count is 1: 
        return ["0", "1", "8"]
    else: 
        smallerGroup = getStrobNumber(count-2)

    stroblist = list()
    for smaller in smallerGroup: 
        stroblist.extend([
            "1" + smaller + "1",
            "6" + smaller + "9", 
            "9" + smaller + "6", 
            "8" + smaller + "8"
            ])

    return stroblist

print(getStrobNumber(3))





