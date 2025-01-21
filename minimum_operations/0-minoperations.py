#!/usr/bin/python3
"""
Calculates the minimum operations needed to achieve exactly n 'H' characters in a file.
"""

def minOperations(n):
    if n < 2:
        return 0

    operations = 0
    factor = 2

    while n > 1:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1

    return operations
