#include "main.h"

/**
 * _strcat - concatenat double strings
 * @dest: Copied string char pointer
 * @src: Constant char pointer source of the string
 * Return: The dest
 */
char *_strcat(char *dest, const char *src)
{
	int x;
	int y;

	for (x = 0; dest[x] != '\0'; x++)
		;

	for (y = 0; src[y] != '\0'; y++)
	{
		dest[x] = src[y];
		x++;
	}

	dest[x] = '\0';
	return (dest);
}
/**
 * *_strcpy - Copy the string pointed to by src.
 * @dest: Type char pointer dest of the copied string
 * @src: Type char pointer the source of the string
 * Return: The dest
 */
char *_strcpy(char *dest, char *src)
{

	size_t s;

	for (s = 0; src[s] != '\0'; s++)
	{
		dest[s] = src[s];
	}
	dest[s] = '\0';

	return (dest);
}
/**
 * _strcmp - This compares double strings
 * @s1: Type one string compared
 * @s2: Type two string compared
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int a;

	for (a = 0; s1[a] == s2[a] && s1[a]; a++)
		;

	if (s1[a] > s2[a])
		return (1);
	if (s1[a] < s2[a])
		return (-1);
	return (0);
}
/**
 * _strchr - this locates char in the string
 * @s: Str
 * @c: Char
 * Return: The pointer of the first occurrence of the char c
 */
char *_strchr(char *s, char c)
{
	unsigned int b = 0;

	for (; *(s + b) != '\0'; b++)
		if (*(s + b) == c)
			return (s + b);
	if (*(s + b) == c)
		return (s + b);
	return ('\0');
}
/**
 * _strspn - get length of a prefix substring
 * @s: Initial segment
 * @accept: Bytes accepted
 * Return: The numbers of bytes accepted
 */
int _strspn(char *s, char *accept)
{
	int x, y, bool;

	for (x = 0; *(s + x) != '\0'; x++)
	{
		bool = 1;
		for (y = 0; *(accept + y) != '\0'; y++)
		{
			if (*(s + x) == *(accept + y))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (x);
}

