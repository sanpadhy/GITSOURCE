def pow(x, y):
    if not x:
        return 0
    elif not y:
        return 1

    y_abs = abs(y)

    current_pow = 1
    prev_result, prev_pow = 0, 0
    result = x
    while current_pow <= y_abs:
        prev_result = result
        prev_pow = current_pow
        result *= result
        current_pow *= 2

    prev_result *= pow(x, y_abs - prev_pow)

    return 1/prev_result if y != y_abs else prev_result


print(pow(2, 2))
print(pow(2, 10))
print(pow(10, 3))
print(pow(2, -3))

