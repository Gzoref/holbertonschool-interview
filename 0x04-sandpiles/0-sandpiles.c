#include "sandpiles.h"

/**
* print_grid - Prints a 3 x 3 grid
*
* @grid: 3 x 3 grid
*
* Return: Void
*/
void print_grid(int grid[3][3])
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
* is_stable - Check if square has more than 3 grains
*
* @grid: 3 x 3 grid
*
* Return: 0 if stable, 1 if unstable
*/
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				return (0);
			}
		}
	}
	return (1);
}

/**
* topple - Partitions grains from squares greater than 3
*
* @grid1: 3 x 3 board
*
* @grid2: 3 x 3 board
*
* Return: Void
*/
void topple(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				if (i > 0)
				{
					grid2[i - 1][j]++;
				}
				if (i < 2)
				{
					grid1[i + 1][j]++;
				}

				if (j > 0)
				{
					grid1[i][j - 1]++;
				}

				if (j < 2)
				{
					grid1[i][j + 1]++;
				}
				grid1[i][j] -= 4;
			}
		}
	}
	add_sandpile(grid1, grid2);
}

/**
* add_sandpile - Add two 3 x 3 grid sandpiles
*
* @grid1: 3 x 3 board
*
* @grid2: 3 x 3 board
*
* Return: Return value
*/
void add_sandpile(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			grid2[i][j] = 0;
		}
	}
}

/**
* sandpiles_sum - Computes the sum of sanpiles
*
* @grid1: 3 x 3 board
*
* @grid2: 3 x 3 board
*
* Return: Void
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			grid2[i][j] = 0;
		}
	}
	add_sandpile(grid1, grid2);
	while (!is_stable(grid1))
	{
		print_grid(grid1);
		topple(grid1, grid2);
	}
}
