#include "main.h"

/**
 * copy_info - copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */
char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_env - sets an environment variable
 *
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @datash: data structure (environ)
 * Return: no return
 */
void set_env(char *name, char *value, data_shell *datash)
{
	int i;
	char *var_env, *name_env;

	for (i = 0; datash->_environ[i]; i++)
	{
		var_env = _strdup(datash->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(datash->_environ[i]);
			datash->_environ[i] = copy_info(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	datash->_environ = _reallocdp(datash->_environ, i + 2, sizeof(char *));
	datash->_environ[i] = copy_info(name, value);
	datash->_environ[i + 1] = NULL;
}

/**
 * _setenv - compares env variables names
 * with the name passed.
 * @datashell: data relevant (env name and env value)
 *
 * Return: 1 on success.
 */
int _setenv(data_shell *datashell)
{
	if (datashell->args[1] == NULL || datashell->args[2] == NULL)
	{
		get_error(datashell, -1);
		return (1);
	}

	set_env(datashell->args[1], datashell->args[2], datashell);

	return (1);
}

/**
 * _unsetenv - deletes an environment variable
 *
 * @shelldata: data relevant (env name)
 *
 * Return: 1 on success.
 */
int _unsetenv(data_shell *shelldata)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int i, j, k;

	if (shelldata->args[1] == NULL)
	{
		get_error(shelldata, -1);
		return (1);
	}
	k = -1;
	for (i = 0; shelldata->_environ[i]; i++)
	{
		var_env = _strdup(shelldata->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, shelldata->args[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		get_error(shelldata, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * i);
	for (j = 0; shelldata->_environ[j]; j++)
	{
		if (j != k)
			realloc_environ[j] = shelldata->_environ[j];
		else
			free(shelldata->_environ[j]);
	}
	realloc_environ[i - 1] = NULL;
	free(shelldata->_environ);
	shelldata->_environ = realloc_environ;
	return (1);
}


