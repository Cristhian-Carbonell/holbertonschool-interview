#include "sandpiles.h"

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: sandpiles stable
 * @grid2: sandpiles stable
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum(grid1, grid2);

	while (check(grid1) == 0)
	{
		print_grid(grid1);
		changeCompare(grid1);
	}
}

/**
 * sum - computes the sum of two sandpiles
 * @grid1: sandpiles stable
 * @grid2: sandpiles stable
 */
void sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
}

/**
 * check - compare if the sandpiles is stable
 * @grid1: sandpiles stable
 *
 * Return: 1 if stable or 0 not stable
 */
int check(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * changeCompare - compare each sandpiles and append
 * the sum into another matrix
 * @grid1: sandpiles stable
 */
void changeCompare(int grid1[3][3])
{
	int i, j, newGrid[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			newGrid[i][j] = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] = grid1[i][j] - 4;
				if ((i - 1 >= 0) && (i - 1 < 3))
					newGrid[i - 1][j] += 1;
				if ((j - 1 >= 0) && (j - 1 < 3))
					newGrid[i][j - 1] += 1;
				if ((i + 1 >= 0) && (i + 1 < 3))
					newGrid[i + 1][j] += 1;
				if ((j + 1 >= 0) && (j + 1 < 3))
					newGrid[i][j + 1] += 1;
			}
		}
	}
	sum(grid1, newGrid);
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
    	int i, j;

	printf("=\n");
   	for (i = 0; i < 3; i++)
    	{
        	for (j = 0; j < 3; j++)
        t 	{
            		if (j)
                		printf(" ");
	            	printf("%d", grid[i][j]);
        	}
        	printf("\n");
    	}
}

