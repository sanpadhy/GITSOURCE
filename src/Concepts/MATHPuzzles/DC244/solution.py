# The Sieve of Eratosthenes is an algorithm used to generate all prime numbers smaller than N. The method 
# is to take increasingly larger prime numbers, and mark their multiples as composite.

# For example, to find all primes less than 100, we would first mark [4, 6, 8, ...] (multiples of two), 
# then [6, 9, 12, ...] (multiples of three), and so on. Once we have done this for all primes less than N, 
# the unmarked numbers that remain will be prime.

# Implement this algorithm.

# Bonus: Create a generator that produces primes indefinitely (that is, without taking N as an input).

import time

def nextPrimeNum(primeset): 
    num = primeset[-1]+1
    while True: 
        if all(num % x for x in primeset):
            time.sleep(0.01)
            yield(num)
        num += 1

def getPrime(): 
    firstPrime = 2
    primenum = [firstPrime]
    print(primenum)
    for prime in nextPrimeNum(primenum): 
        primenum.append(prime)
        print(primenum)

    return primenum

print(getPrime())
