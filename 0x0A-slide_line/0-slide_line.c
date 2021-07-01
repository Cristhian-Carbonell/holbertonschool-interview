#include "slide_line.h"

/**
 * slide_line - function that slides and merges an array of integers
 * @line: points to an array of integers containing size elements
 * @size: elements
 * @direction: can be either: SLIDE_LEFT and SLIDE_RIGHT
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	int *current = NULL, *left = NULL, *right = NULL;

	if (direction == SLIDE_LEFT)
	{
		current = line;
		left = current;

		while (left < line + (size - 1))
		{
			while (*left == 0 && left < line + (size - 1))
				left++;

			right = left + 1;
			while (right < line + (size))
			{
				if (*right == *left)
				{
					*current = *left * 2;
					if (current != left)
						*left = 0;

					*right = 0;
					current++;
					break;
				}
				else
					right++;
			}

			left++;
		}

		if (*(line + size - 1) && !*current)
		{
			*current = *(line + size - 1);
			*(line + size - 1) = 0;
		}
	}
	return (1);
}
