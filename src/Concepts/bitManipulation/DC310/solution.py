def getNumSetBits(num):
    if not num: 
        return 0

    pow_num, power_of_two = 0, 1
    while power_of_two-1 <= num:
        print(pow_num, power_of_two)
        power_of_two *= 2 
        pow_num += 1

    power_of_two //= 2
    pow_num -= 1
    
    print(pow_num, power_of_two)

    remainder = num - (power_of_two - 1)
    print(remainder)
    set_bits = ((pow_num * power_of_two)//2)
    print(set_bits)

    set_bits = set_bits + getNumSetBits(remainder)

    return set_bits

print(getNumSetBits(1))
