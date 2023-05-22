#include "main.h"

/**
 * _strdup - duplicates string in the heap memory
 * @s: Type char pointer string
 * Return: Duplicated string
 */
char *_strdup(const char *s)
{
	char *new;
	size_t len;

	len = _strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, len + 1);
	return (new);
}

/**
 * _strlen - Returns the lenght of a string
 * @s: Type character pointer
 * Return: Always 0
 */
int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}
/**
 * cmp_chars - Compares character of the strings
 * @str: Input string
 * @delim: Delimiter
 *
 * Return: 1 if it equals, 0 if not
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int a, b, c;

	for (a = 0, c = 0; str[a]; a++)
	{
		for (b = 0; delim[b]; b++)
		{
			if (str[a] == delim[b])
			{
				c++;
				break;
			}
		}
	}
	if (a == c)
		return (1);
	return (0);
}

/**
* _strtok - using delimiter to splits a string
 * @str: Input string
 * @delim: Delimiter
 *
 * Return: String splited
 */
char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int a, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);

		splitted = str; /*Store first address*/
		a = _strlen(str);

		str_end = &str[a]; /*store last address*/

	}
	str_start = splitted;
	if (str_start == str_end) /*Reaching the end*/
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		if (splitted != str_start) /*Breaking loop finding the next token*/
			if (*splitted && *(splitted - 1) == '\0')
				break;
		for (a = 0; delim[a]; a++) /*Replacing delimiter for null char*/
		{
			if (*splitted == delim[a])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - defined if a string passed is a number or not
 *
 * @s: Input string
 * Return: 1 if string is a number 0 in other case
 */
int _isdigit(const char *s)
{
	unsigned int a;

	for (a = 0; s[a]; a++)
	{
		if (s[a] < 48 || s[a] > 57)
			return (0);
	}
	return (1);
}

