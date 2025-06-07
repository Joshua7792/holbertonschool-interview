#!/usr/bin/python3
"""
Rotate 2D Matrix 90 degrees clockwise in-place
"""


def rotate_2d_matrix(matrix):
    """
    Rotate an n x n 2D matrix 90 degrees clockwise in-place.

    Args:
        matrix: n x n 2D matrix to rotate
    """
    n = len(matrix)

    # Rotate layer by layer from outside to inside
    for layer in range(n // 2):
        first = layer
        last = n - 1 - layer

        # Rotate elements in current layer
        for i in range(first, last):
            offset = i - first

            # Save top element
            top = matrix[first][i]

            # Move left to top
            matrix[first][i] = matrix[last - offset][first]

            # Move bottom to left
            matrix[last - offset][first] = matrix[last][last - offset]

            # Move right to bottom
            matrix[last][last - offset] = matrix[i][last]

            # Move top to right
            matrix[i][last] = top
