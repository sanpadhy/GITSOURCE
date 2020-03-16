def divide(dividend, divisor):
    if not divisor:
        return

    current_sum = 0
    quotient = 0
    while current_sum <= dividend:
        quotient += 1
        current_sum += divisor

    return quotient - 1


divide(1, 1)
divide(0, 1)
divide(12, 3)
divide(13, 3)
divide(25, 5)
divide(25, 7)
