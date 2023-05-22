#include "main.h"

/**
 * cd_shell - Changes current directory
 *
 * @datash: Relevant data
 * Return: 1 when successful
 */
int cd_shell(data_shell *datash)
{
	char *dir;
	int isddash, ishome, ishome2;

	dir = datash->args[1];

	if (dir == NULL)
	{
		isddash = _strcmp("--", dir);
		ishome = _strcmp("$HOME", dir);
		ishome2 = _strcmp("~", dir);
	}

	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		cd_to_home(datash);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		cd_previous(datash);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd_dot(datash);
		return (1);
	}

	cd_to(datash);

	return (1);
}
