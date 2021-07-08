#include "menger.h"

/**
 * menger - function that draws a 2D Menger Sponge
 * @level: is the level of the Menger Sponge to draw
 */
void menger(int level)
{
	int axis_x, axis_y;
	int dimension = 1;
	int number;

	if (level >= 0)
	{
		dimension = pow(3, level);
		for (axis_x = 0; axis_x < dimension; axis_x++)
		{
			for (axis_y = 0; axis_y < dimension; axis_y++)
			{
				for (number = dimension / 3; number > 0; number /= 3)
					if ((axis_x % (number * 3)) / number == 1 &&
					(axis_y % (number * 3)) / number == 1)
						break;
				if (number)
					printf(" ");
				else
					printf("#");
			}
			printf("\n");
		}
	}
}
