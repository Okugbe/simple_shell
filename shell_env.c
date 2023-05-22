#include "main.h"
#include <string.h>

/**
 * cmp_env_name - compares env variables names
 * with the name passed.
 * @nenv: name of the environment variable
 * @name: name passed
 *
 * Return: 0 if they are not equal, otherwise the length of the matched part.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}
	return (i + 1);
}
/**
 * _getenv - get an environment variable
 * @name: name of the environment variable
 * @_environ: environment variable
 *
 * Return: value of the environment variable if found, otherwise NULL.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	/* Initialize ptr_env value */
	ptr_env = NULL;
	mov = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (i = 0; _environ[i]; i++)
	{
		/* If name and env are equal */
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + mov);
}
/**
 * _env - prints the environment variables
 *
 * @datash: data relevant
 * Return: 1 on success.
 */
int _env(data_shell *datash)
{
int i;

for (i = 0; datash->_environ[i]; i++)
{
size_t len = strlen(datash->_environ[i]);

write(STDOUT_FILENO, datash->_environ[i], len);
write(STDOUT_FILENO, "\n", 1);
}
datash->status = 0;
return (1);
}

