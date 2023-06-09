#include "main.h"

/**
 * get_len - Get the length of a number.
 *
 * @n: The number to determine the length of.
 *
 * Return: The length of the number.
 */
int get_len(int n)
{
	unsigned int n1;
	int length = 1;

	/* Check if the number is negative */
	if (n < 0)
	{
		length++;
		n1 = n * -1;
	}
	else
	{
		n1 = n;
	}

	/* Calculate the length of the number */
	while (n1 > 9)
	{
		length++;
		n1 = n1 / 10;
	}

	return (length);
}

/**
 * aux_itoa - Convert an integer to a string.
 *
 * @n: The integer to convert.
 *
 * Return: The converted string.
 */
char *aux_itoa(int n)
{
	unsigned int n1;
	int length = get_len(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (length + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + length) = '\0';

	/* Check if the number is negative */
	if (n < 0)
	{
		n1 = n * -1;
		buffer[0] = '-';
	}
	else
	{
		n1 = n;
	}

	length--;
	/* Convert the number to a string */
	do {
		*(buffer + length) = (n1 % 10) + '0';
		n1 = n1 / 10;
		length--;
	} while (n1 > 0);

	return (buffer);
}

/**
 * _atoi - Convert a string to an integer.
 *
 * @s: The input string to convert.
 *
 * Return: The converted integer.
 */
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	/* Process each character in the string */
	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		/* Check if the number is negative */
		if (*(s + count) == '-')
			pn *= -1;

		/* Check if the character is a digit */
		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	/* Convert the string to an integer */
	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}


