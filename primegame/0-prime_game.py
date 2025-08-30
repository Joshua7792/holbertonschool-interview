#!/usr/bin/python3
"""Prime Game module"""


def isWinner(x, nums):
    """
    Determine winner of prime game across multiple rounds

    Args:
        x: number of rounds
        nums: array of n values for each round

    Returns:
        Name of player with most wins, or None if tied
    """
    if not nums or x < 1:
        return None

    # Find maximum n to optimize sieve generation
    max_n = max(nums)

    # Generate primes up to max_n using Sieve of Eratosthenes
    def sieve_of_eratosthenes(limit):
        if limit < 2:
            return []

        is_prime = [True] * (limit + 1)
        is_prime[0] = is_prime[1] = False

        for i in range(2, int(limit**0.5) + 1):
            if is_prime[i]:
                for j in range(i * i, limit + 1, i):
                    is_prime[j] = False

        return [i for i in range(2, limit + 1) if is_prime[i]]

    # Get all primes up to max_n
    primes = sieve_of_eratosthenes(max_n)

    # Precompute number of primes <= each number for efficiency
    prime_count = [0] * (max_n + 1)
    prime_idx = 0

    for i in range(1, max_n + 1):
        prime_count[i] = prime_count[i-1]
        if prime_idx < len(primes) and primes[prime_idx] == i:
            prime_count[i] += 1
            prime_idx += 1

    maria_wins = 0
    ben_wins = 0

    # Play each round
    for i in range(x):
        if i >= len(nums):
            break

        n = nums[i]
        if n < 1:
            ben_wins += 1  # Maria can't make a move
            continue

        # Count number of moves in this game
        # Each prime that can be chosen counts as one move
        moves = prime_count[n]

        # If odd number of moves, Maria wins (she goes first)
        # If even number of moves, Ben wins
        if moves % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    # Determine overall winner
    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
