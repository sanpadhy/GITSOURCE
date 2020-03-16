
# There are N prisoners standing in a circle, waiting to be executed. The executions are carried out 
# starting with the kth person, and removing every successive kth person going clockwise until there is no one left.

# Given N and k, write an algorithm to determine where a prisoner should stand in order to be the last survivor.

# For example, if N = 5 and k = 2, the order of executions would be [2, 4, 1, 5, 3], so you should return 3.

# Bonus: Find an O(log N) solution if k = 2.

def findPerson(n, k):
    next_prisoner_index = 0
    last_prisoner = 0

    prisoners = list(range(1, n+1))

    while prisoners: 
        next_prisoner_index = (next_prisoner_index + k - 1)%len(prisoners)

        last_prisoner = prisoners[next_prisoner_index]

        prisoners = prisoners[:next_prisoner_index] + prisoners[next_prisoner_index+1:]

    return last_prisoner

print(findPerson(5, 2))

