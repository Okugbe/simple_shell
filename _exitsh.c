#include "main.h"

/**
 * exit_shell - Exits the shell
 *
 * @datash: data relevant (status and args)
 * Return: 0 on success.
 */
int exit_shell(data_shell *datash)
{
	unsigned int ustatus;

	if (datash->args[1] != NULL)
	{
		ustatus = _atoi(datash->args[1]);
		if (!_isdigit(datash->args[1]) || _strlen(datash->args[1]) > 10
				|| ustatus > (unsigned int)INT_MAX)
		{
			get_error(datash, 2);
			datash->status = 2;
			return (1);
		}
		datash->status = ustatus % 256;
	}
	return (0);
}



