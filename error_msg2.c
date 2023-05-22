#include "main.h"

/**
 * error_env - Generates an error message for the "env" command in get_env.
 *
 * @shelldata: Data relevant to the shell (counter, arguments).
 *
 * Return: The error message.
 */
char *error_env(data_shell *shelldata)
{
	int length;
	char *err;
	char *ver_str;
	char *msg;

	ver_str = aux_itoa(shelldata->counter);
	msg = ": Unable to add/remove from environment\n";
	/* Calculate the length of the error message */
	length = _strlen(shelldata->av[0]) + _strlen(ver_str) +
		_strlen(shelldata->args[0]) + _strlen(msg) + 4;
	err = malloc(sizeof(char) * (length + 1));
	if (err == 0)
	{
		free(err);
		free(ver_str);
		return (NULL);
	}
	/* Build the error message */
	_strcpy(err, shelldata->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, shelldata->args[0]);
	_strcat(err, msg);
	_strcat(err, "\0");
	free(ver_str);
	return (err);
}

/**
 * error_path_126 - Generates an error message for the "path" command
 * and failure due to denied permission.
 *
 * @shelldata: Data relevant to the shell (counter, arguments).
 *
 * Return: The error message.
 */
char *error_path_126(data_shell *shelldata)
{
	int length;
	char *ver_str;
	char *err;

	ver_str = aux_itoa(shelldata->counter);
	length = _strlen(shelldata->av[0]) + _strlen(ver_str);/* Get message length */
	length += _strlen(shelldata->args[0]) + 24;
	err = malloc(sizeof(char) * (length + 1));
	if (err == 0)
	{
		free(err);
		free(ver_str);
		return (NULL);
	}
	_strcpy(err, shelldata->av[0]);/* Build error message */
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, shelldata->args[0]);
	_strcat(err, ": Permission denied\n");
	_strcat(err, "\0");
	free(ver_str);
	return (err);
}
