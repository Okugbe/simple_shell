#include "main.h"

/**
 * rev_string - Reverses string
 * @s: String inputs
 * Return: No return
 *
 */

void rev_string(char *s)
{
	int count = 0, x;
	char *start, *end, temp;

	while (s[count] != '\0')
	{
		count++;
	}
	start = s;
	end = s + count - 1;

	for (x = 0; x < count / 2; x++)
	{
		temp = *end;
		*end = *start;
		*start = temp;
		start++;
		end--;
	}
}

