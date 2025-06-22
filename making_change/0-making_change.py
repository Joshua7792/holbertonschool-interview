#!/usr/bin/python3
"""
Making Change Module
"""


def makeChange(coins, total):
    """
    Determines the fewest number of coins needed to meet a given total.
    
    Args:
        coins (list): List of coin denominations (positive integers).
        total (int): Target amount.

    Returns:
        int: Minimum number of coins needed to make up the total.
             Returns -1 if it's not possible to make the total.
    """
    if total <= 0:
        return 0

    # Use a large number for comparison
    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for coin in coins:
        for amount in range(coin, total + 1):
            dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
