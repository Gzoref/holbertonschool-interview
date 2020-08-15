#include "sandpiles.h"

/**
* print_grid - Prints a 3 x 3 grid
*
* @grid: 3 x 3 grid
*
* Return: Void
*/
void _print_grid(int grid[3][3])
{
	int i, j;

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
				/* Partion grain up */
				if (i - 1 >= 0 && i < 3)
				{
					grid2[i - 1][j]++;
				}
				/* Partion grain down */
				if (i + 1 >= 0 && i + 1 < 3)
				{
					grid2[i + 1][j]++;
				}

				/* Partion grain left */
				if (j - 1 >= 0 && j - 1 < 3)
				{
					grid2[i][j - 1]++;
				}

				/* Partion grain right */
				if (j + 1 >= 0 && j + 1 < 3)
				{
					grid2[i][j + 1]++;
				}

				/* Partition grain off the board */
				grid2[i][j] -= 4;
			}
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
			/* Sum grid1 and grid2 */
			grid1[i][j] += grid2[i][j];
		}
	}
}
