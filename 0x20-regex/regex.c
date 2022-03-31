#include "regex.h"

/**
 *
 */
int checkPoint(char const *pattern)
{
	int index = 0;

	while (pattern[index] != '\0')
	{
		if (pattern[index] == '.')
			return (0);
		index++;
	}

	return (1);
}

/**
 *
 */
int alphabet(char const *pattern)
{
	int len = strlen(pattern) - 1;

	if (pattern[len] == '*' || pattern[len] == 'Z')
		return (1);
	return (0);
}

int regex(char const *str, char const *pattern)
{
	int i = 0, j = 0;

	while (str[i] != '\0')
	{
		if (pattern[j] == 'Z' && pattern[j + 1] == '*')
		{
			j += 2;
			continue;
		}
		if (pattern[j] == '*' || pattern[j] == '.')
		{
			if (checkPoint(pattern))
				if (str[i] != pattern[j - 1] && pattern[j - 1] != '.')
					return (0);
			if (pattern[j + 1] == 'o')
			{
				j++;
				if (pattern[j + 1] == '.')
				{
					j++;
					if (pattern[j + 1] == '\0')
						return (1);
				}
				else if (pattern[j + 1] == '\0')
					return (0);
				j--;
			}
			if (pattern[j] == '.')
				j++;
			i++;
			continue;
		}
		if (str[i] == '.' || str[i] == '*')
			return (0);
		if (str[i] != pattern[j])
			return (0);
		i++, j++;
	}
	return (1);
}
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
	int i = 0;
	int len = strlen(pattern) - 1;

	if (str[i] == '\0')
	{
		if (pattern[i] == '\0')
		{
			return (1);
		}
		else
		{
			if (pattern[i + 1] == '*')
				return (1);
		}
		return (0);
	}
	else
	{
		if (str[i] == pattern[i])
			if (str[i + 1] == '\0' && pattern[i + 1] == '*')
				if (pattern[i + 2] == '\0')
					return (1);
	}
	
	if (str[i] == 'A' && str[strlen(str) - 1] == 'Z')
		return (alphabet(pattern));
	if (str[i] == pattern[i])
		if (str[i + 1] == '\0' && pattern[i + 1] == '\0')
			return (1);

	if (str[i + 1] == '\0' && pattern[len] != '*')
		return (0);
	if (str[i] != '\0')
		return (regex(str, pattern));
	return (1);
}
