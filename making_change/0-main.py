#!/usr/bin/python3
"""
Main file for testing
"""

makeChange = __import__('0-making_change').makeChange

print(makeChange([1, 2, 25], 37))  # Expected: 7 (25+10+2)
print(makeChange([1256, 54, 48, 16, 102], 1453))  # Expected: -1