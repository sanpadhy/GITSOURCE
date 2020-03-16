# The power set of a set is the set of all its subsets. Write a function that, given a set, generates its power set.

# For example, given the set {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.

# You may also use a list or array to represent a set.

def getPowerSet(arr): 
    if len(arr) == 0: 
        return [set()]

    powerset = list()
    firstNum = arr[0]

    childsets = getPowerSet(arr[1:])
    powerset.extend(childsets)

    for childset in childsets: 
        newset = childset.copy()
        newset.add(firstNum)
        powerset.append(newset)

    return powerset

    
print(getPowerSet([1, 2, 3]))
