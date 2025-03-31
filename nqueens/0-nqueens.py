#!/usr/bin/python3
import sys


def is_safe(board, row, col, N):
    # Check if there's a queen in the same column
    for i in range(row):
        if board[i] == col or \
           board[i] == col - row + i or \
           board[i] == col + row - i:
            return False
    return True


def solve_n_queens(N):
    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    def backtrack(queens, row):
        if row == N:
            return [queens[:]]

        solutions = []
        for col in range(N):
            if is_safe(queens, row, col, N):
                queens[row] = col
                solutions.extend(backtrack(queens, row + 1))
                queens[row] = -1  # Backtrack
        return solutions

    queens = [-1] * N
    return backtrack(queens, 0)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    solutions = solve_n_queens(N)
    for sol in solutions:
        print([[i, sol[i]] for i in range(N)])
