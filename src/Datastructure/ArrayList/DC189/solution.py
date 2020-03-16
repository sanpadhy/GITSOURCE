# This problem was asked by Google.

# Given an array of elements, return the length of the longest subarray where all its elements are distinct.

# For example, given the array [5, 1, 3, 5, 2, 3, 4, 1], return 5 as the longest subarray of distinct elements is [5, 2, 3, 4, 1].

def LongestSubArrayWithDistinct(arr):
    longest = 0
    seenNum = set()
    longest_seq = list()
    current_seq = list()

    for i, var in enumerate(arr):
        if var in seenNum: 
            current_len = len(current_seq)
            if current_len > longest: 
                longest = current_len
                longest_seq = current_seq
                current_seq = []
                seenNum = set()
        
        seenNum.add(var)
        current_seq.append(var)

    if len(current_seq) > longest: 
        longest = len(current_seq)
        longest_seq = current_seq

    return (longest, longest_seq)
            


arr = [5, 1, 3, 5, 2, 3, 4, 1]
print(LongestSubArrayWithDistinct(arr))
