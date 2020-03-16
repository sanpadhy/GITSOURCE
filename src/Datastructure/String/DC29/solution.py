# Run-length encoding is a fast and simple method of encoding strings. The basic idea is to represent repeated successive characters as a single count and character. For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".

# Implement run-length encoding and decoding. You can assume the string to be encoded have no digits and consists solely of alphabetic characters. You can assume the string to be decoded is valid.


def runLengthEncoding(s):
    if len(s) == 0: 
        return ""

    first_char = s[0]
    count = 0
    result = list()
    i = 1

    for c in s: 
        if c == first_char : 
            count += 1
            continue

        result.append(str(count))
        result.append(first_char)
        first_char = c
        count = 1
    
    if(count > 0): 
        result.append(str(count))
        result.append(first_char)

    return "".join(result)

def runLengthDecoding(s): 
    if len(s) == 0: 
        return ""

    count = 1
    first = 0
    num = 0
    result = list()

    for i in range(len(s)):
        if s[i].isnumeric(): 
            num = 10 * num + int(s[i])
            continue

        count = num 
        result.append(count * s[i])
        num = 0
        count = 1

    return "".join(result)


print(runLengthEncoding("AAAABBCCC"))
print(runLengthDecoding("11A3B"))
