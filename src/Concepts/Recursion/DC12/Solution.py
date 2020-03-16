# There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N, 
# write a function that returns the number of unique ways you can climb the staircase. The order of the steps matters.

# For example, if N is 4, then there are 5 unique ways:

# 1, 1, 1, 1
# 2, 1, 1
# 1, 2, 1
# 1, 1, 2
# 2, 2

# What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive 
# integers X? For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.


def findAllSteps(nsteps, steps): 
    psteps = list()

    if nsteps < min(steps): 
        return psteps

    for step in steps: 
        if (nsteps == step): 
            psteps.append([step])
        else: 
            childSteps = findAllSteps(nsteps-step, steps)

            for childStep in childSteps: 
                psteps.append([step] + childStep)

    return psteps

print(findAllSteps(4, [1, 2]))



