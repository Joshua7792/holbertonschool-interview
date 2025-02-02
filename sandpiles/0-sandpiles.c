#include "sandpiles.h"
#include <stdio.h>

/**
 * print_grid - Prints a 3x3 grid
 * @grid: The grid to print
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - Checks if the grid is stable
 * @grid: The grid to check
 *
 * Return: 1 if stable, 0 otherwise
 */
static int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * topple - Topples an unstable grid
 * @grid: The grid to topple
 */
static void topple(int grid[3][3])
{
	int i, j;
	int temp[3][3] = {0};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				temp[i][j] -= 4;
				if (i > 0)
					temp[i - 1][j] += 1;
				if (i < 2)
					temp[i + 1][j] += 1;
				if (j > 0)
					temp[i][j - 1] += 1;
				if (j < 2)
					temp[i][j + 1] += 1;
			}
		}
	}
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid[i][j] += temp[i][j];
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: First grid and result holder
 * @grid2: Second grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	while (!is_stable(grid1))
	{
		print_grid(grid1);
		topple(grid1);
	}
}
