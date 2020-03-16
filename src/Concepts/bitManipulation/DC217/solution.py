# We say a number is sparse if there are no adjacent ones in its binary representation. For example, 21 (10101) 
# is sparse, but 22 (10110) is not. For a given input N, find the smallest sparse number greater than or equal to N.

# Do this in faster than O(N log N) time.

def findNextSparse(num): 
    num_bin = str(bin(num))[2:]

    print(num_bin)

    resultBit = ""
    prevBit = 0
    curBit = 0
    flag = False

    for i, curBit in enumerate(num_bin[1:]): 
        if curBit == '1' and prevBit == '1':  
               flag = True 

        print(i)
        if flag == True: 
            resultBit += '0' * (len(num_bin)-i)
            break
        else: 
            resultBit += curBit
    
        prevBit = curBit 

    print(resultBit)
    if(flag):
        if resultBit[0] == '1': 
            resultBit = '10' + resultBit[1:]
        else: 
            resultBit = '1'+ resultBit[]

    print(resultBit)
    return int(resultBit, base=2)

num = 22
print(findNextSparse(num))

10110
0110 -- 1000
0
1
2
01000
11000
24

