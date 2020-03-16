def get_perfect_number(n):
    tmp_sum = 0
    for char in str(n):
        tmp_sum += int(char)
        
    return (n * 10) + (10 - tmp_sum)


print(get_perfect_number(1))
print(get_perfect_number(2))
print(get_perfect_number(3))
print(get_perfect_number(10))
print(get_perfect_number(11))
print(get_perfect_number(19))
