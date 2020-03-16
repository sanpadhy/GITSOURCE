def get_set_bits(num):
    if not num:
        return 0

    max_pow, max_pow_of_two = 0, 1
    while max_pow_of_two - 1 <= num:
        print(max_pow, max_pow_of_two)
        max_pow_of_two *= 2
        max_pow += 1
    max_pow_of_two //= 2
    max_pow -= 1

    print(max_pow, max_pow_of_two)

    remainder = num - (max_pow_of_two - 1)
    print(remainder)
    set_bits = ((max_pow * max_pow_of_two) // 2)
    print(set_bits)
    set_bits = set_bits + get_set_bits(remainder)

    return set_bits

print(get_set_bits(1))
