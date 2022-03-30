#include "regex.h"

/**
 * regex_match - function that checks whether a given pattern
 * matches a given string.
 * @str: is the string to scan
 * @pattern: is the regular expression
 *
 * Return: 1 if the pattern matches the string, or 0 if it doesn’t
 */
int regex_match(char const *str, char const *pattern)
{
	int index = 0;
	int element = 0;

	while (str[index] != '\0')
	{
		if (pattern[element] == 'Z' && pattern[element++] == '*')
		{
			element += 2;
			continue;
		}
		if (pattern[element] == '*' || pattern[element] == '.')
		{
			if (pattern[element] == '.')
				element++;
			index++;
			continue;
		}

		if (str[index] == '.' || str[index] == '*')
			return (0);

		if (str[index] != pattern[element])
			return (0);
		index++, element++;
	}

	return (1);
}
