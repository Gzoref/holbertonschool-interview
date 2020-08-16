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
	int row, col;

	printf("=\n");
	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			if (col)
				printf(" ");
			printf("%d", grid[row][col]);
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
	int row, col;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			if (grid[row][col] > 3)
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
	int row, col;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			if (grid1[row][col] > 3)
			{
				/* Send one grain of sand up */
				if (row > 0)
				{
					grid2[row - 1][col]++;
				}

				/* Send one grain of sand down */
				if (row < 2)
				{
					grid1[row + 1][col]++;
				}

				/* Send one grain of sand left */
				if (col > 0)
				{
					grid1[row][col - 1]++;
				}

				/* Send one grain of sand right */
				if (col < 2)
				{
					grid1[row][col + 1]++;
				}

				/* Send one grain of sand off the grid */
				grid1[row][col] -= 4;
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
	int row, col;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			grid1[row][col] += grid2[row][col];
			grid2[row][col] = 0;
			//memset(grid2, 0, sizeof(int) * 9);
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
	int row, col;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			grid1[row][col] += grid2[row][col];
			grid2[row][col] = 0;
		}
	}
	add_sandpile(grid1, grid2);
	while (!is_stable(grid1))
	{
		print_grid(grid1);
		topple(grid1, grid2);
	}
}
