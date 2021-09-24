#include "holberton.h"

/**
 * check - checks if string is number
 * @number: string
 *
 * Return: 1 if number, 0 if not
 */
int check(char *number)
{
	int i;

	for (i = 0; number[i] != '\0'; i++)
	{
		if (isdigit(number[i]))
			return (0);
	}

	return (1);
}


/**
 * memory - reserves memory initialized to 0
 * @full_length: number of bytes
 *
 * Return: pointer
 */
char *memory(unsigned int full_length)
{
	unsigned int i;
	char *pointer;

	pointer = malloc(full_length + 1);
	if (!pointer)
		return (0);
	for (i = 0; i < full_length; i++)
		pointer[i] = '0';
	pointer[i] = '\0';

	return (pointer);
}

/**
 * multipliesNumbers - program that multiplies two positive numbers
 * @argv: array of character pointers
 *
 */
void multipliesNumbers(char **argv)
{
	int i, j, len1, len2, lenfull;
	int mul, add, ten, ten2, tl, zer = 0;
	char *pointer;

	len1 = strlen(argv[1]), len2 = strlen(argv[2]);
	lenfull = len1 + len2;
	pointer = memory(lenfull);
	for (i = len2 - 1; i >= 0; i--)
	{
		ten = 0, ten2 = 0;
		for (j = len1 - 1; j >= 0; j--)
		{
			tl = i + j + 1;
			mul = (argv[1][j] - '0') * (argv[2][i] - '0') + ten;
			ten = mul / 10;
			add = (pointer[tl] - '0') + (mul % 10) + ten2;
			ten2 = add / 10;
			pointer[tl] = (add % 10) + '0';
		}
		pointer[tl - 1] = (ten + ten2) + '0';
	}
	if (pointer[0] == '0')
		zer = 1;
	for (; zer < lenfull; zer++)
		_putchar(pointer[zer]);
	_putchar('\n');
	free(pointer);
}



/**
 * main - entry point
 * @argc: contains the number of arguments that have been entered.
 * @argv: array of character pointers.
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	int i;
	char *error = "Error";

	if (argc != 3 || check(argv[1]) || check(argv[2]))
	{
		for (i = 0; error[i] != '\0'; i++)
			_putchar(error[i]);
		_putchar('\n');
		exit(98);
	}
	if (atoi(argv[1]) == 0 || atoi(argv[2]) == 0)
	{
		_putchar('0');
		_putchar('\n');
		exit(0);
	}
	multipliesNumbers(argv);

	return (0);
}