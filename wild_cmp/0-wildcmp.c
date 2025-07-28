#include "holberton.h"

/**
 * wildcmp - compares two strings with wildcard support
 * @s1: first string to compare
 * @s2: second string (can contain '*' wildcards)
 *
 * Description: The '*' character in s2 can match any string
 * Return: 1 if strings can be considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	/* Base case: end of pattern */
	if (*s2 == '\0')
		return (*s1 == '\0');

	/* If we encounter '*' */
	if (*s2 == '*')
	{
		/* Skip consecutive asterisks recursively */
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));

		/* If pattern ends with '*', match everything */
		if (*(s2 + 1) == '\0')
			return (1);

		/* Try matching '*' with empty string first */
		if (wildcmp(s1, s2 + 1))
			return (1);

		/* If s1 is not empty, try matching '*' with current char and more */
		if (*s1 != '\0')
			return (wildcmp(s1 + 1, s2));

		/* No match found */
		return (0);
	}

	/* If current characters don't match, no match */
	if (*s1 == '\0' || *s1 != *s2)
		return (0);

	/* Characters match, continue with next characters */
	return (wildcmp(s1 + 1, s2 + 1));
}
