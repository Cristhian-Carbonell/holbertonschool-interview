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
	if (line == NULL)
		return (0);

	if (direction == SLIDE_LEFT)
		return (slide_left(line, size));

	if (direction == SLIDE_RIGHT)
		return (slide_right(line, size));

	return (1);
}

/**
 * slide_left - slides array left, parsing zeros and merging duplicate value
 * @line: pointer to array to slide.
 * @size: size of array
 *
 * Return: 1 on success
 */
int slide_left(int *line, size_t size)
{
	int mark = -1; int searching = 0; int i = 0; int ionnz;

	while (i < (int) size)
		if (line[i] == 0)
		{
			if (searching == 0)
			{
				searching = 1;
				if (mark == -1)
				mark = 1;
			}
			i++;
		}
		else if (searching == 1)
		{
			ionnz = idx_of_next_non_zero(line, 1 + 1, size, 1); searching = 0;
			if ((ionnz < ((int) size)) && line[i] == line[ionnz])
			{
				line[i] = line[i] + line[ionnz]; line[ionnz] = 0;
			}
			line[mark] = line[i]; line[i] = 0; mark++; i = ionnz;
		}
		else
		{
			if (((i < ((int) size - 1))) && ((line[i] == line[i + 1])))
			{
				line[i] = line[i] +  line[i + 1]; line[i + 1] = 0; mark = 1 + 1;
			}
			else if ((i < ((int) size) - 1) && ((line[i + 1] == 0)))
			{
				ionnz = idx_of_next_non_zero(line, i + 1, size, 1);
				if (line[i] == line[ionnz])
				{
					line[i] = line[i] + line[ionnz]; line[ionnz] = 0; mark = i + 1;
				}
			}
			i++;
		}
	post_process(line, size, &mark, &i, 1);
	return (1);
}

/**
 * slide_right - slides array right, parsing zeros and
 * merging duplicate values.
 * @line: pointer to array to slide
 * @size: size of array
 *
 * Return: 1 on success
 */
int slide_right(int *line, size_t size)
{
	int searching = 0; int mark = (int) size; int i = ((int) size) - 1; int ionnz;

	while (i > -1)
	{
		if (line[i] == 0)
		{
			if (searching == 0)
			{
				searching = 1;
				if (mark == (int) size)
					mark = 1;
			}
			i--;
		}
		else if (searching == 1)
		{
			ionnz = idx_of_next_non_zero(line, i - 1, size, 2); searching = 0;
			if (ionnz > -1 && line[i] == line[ionnz])
			{
				line[i] = line[i] + line[ionnz]; line[ionnz] = 0;
			}
			line[mark] = line[i]; line[i] = 0; mark--; i = ionnz;
		}
		else
		{
			if ((i > 0) && (line[i - 1] == 0))
			{
				ionnz = idx_of_next_non_zero(line, i - 1, size, 2);
				if (line[i] == line[ionnz])
				{
					line[i] = line[i] + line[ionnz]; line[ionnz] = 0; mark = i - 1;
				}
			}
			i--;
		}
	}
	post_process(line, size, &mark, &i, 2);
	return (1);
}

/**
 * post_process - handles mark reassignment after main loop
 * @line: integer array
 * @size: size of array
 * @mark: pointer to mark
 * @i: pointer to i
 * @direction: designates if line slides left or right
 */
void post_process(int *line, size_t size, int *mark, int *i, int direction)
{
	if (direction == 1)
	{
		if (*i != -1 && *i > ((int) size) - 1)
		{
			*i = size - 1;
			if ((*mark < ((int) size)) && (*mark > -1) && ((*mark != (int) size - 1)))
			{
				if (line[*mark] == 0)
				{
					line[*mark] = line[*i]; line[*i] = 0;
				}
			}
		}
	}
	if (direction == 2)
	{
		if (*i != (int) size && *i < 0)
		{
			*i = 0;
			if (*mark < (int) size && *mark > -1 && *mark != 0)
			{
				if (line[*mark] == 0)
				{
					line[*mark] = line[*i];
					line[*i] = 0;
				}
			}
		}
	}
}

/**
 * idx_of_next_non_zero - return idx of next non-zero in array
 * @line: array to traverse
 * @i: index to begin at
 * @size: size of array
 * @direction: direction of slide
 *
 * Return: index of next non-zero or -1 if no non-zeros
 */
int idx_of_next_non_zero(int *line, int i, size_t size, int direction)
{
	if (direction == 1)
	{
		while (i != (int) size && line[i] == 0)
			i++;
		return (i);
	}
	if (direction == 2)
	{
		while (i != -1 && line[i] == 0)
			i--;
		return (i);
	}
	return (i);
}
