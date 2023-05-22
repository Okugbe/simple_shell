#include "main.h"

/**
 * strcat_cd - function that concatenates the message for cd error
 *
 * @shelldata: data relevant (directory)
 * @msg: message to print
 * @err: error output message
 * @ver_str: counter lines
 * Return: error message
 */
char *strcat_cd(data_shell *shelldata, char *msg, char *err, char *ver_str)
{
	char *illegal_flag;

	_strcpy(err, shelldata->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, shelldata->args[0]);
	_strcat(err, msg);
	if (shelldata->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = shelldata->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(err, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(err, shelldata->args[1]);
	}

	_strcat(err, "\n");
	_strcat(err, "\0");
	return (err);
}

/**
 * error_get_cd - error message for cd command in get_cd
 * @shelldata: data relevant (directory)
 * Return: Error message
 */
char *error_get_cd(data_shell *shelldata)
{
	int length, len_id;
	char *err, *ver_str, *msg;

	ver_str = aux_itoa(shelldata->counter);
	if (shelldata->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _strlen(shelldata->args[1]);
	}

	length = _strlen(shelldata->av[0]) + _strlen(shelldata->args[0]);
	length += _strlen(ver_str) + _strlen(msg) + len_id + 5;
	err = malloc(sizeof(char) * (length + 1));

	if (err == 0)
	{
		free(ver_str);
		return (NULL);
	}

	err = strcat_cd(shelldata, msg, err, ver_str);

	free(ver_str);

	return (err);
}

/**
 * error_not_found - generic error message for command not found
 * @shelldata: data relevant (counter, arguments)
 * Return: Error message
 */
char *error_not_found(data_shell *shelldata)
{
	int length;
	char *err;
	char *ver_str;

	ver_str = aux_itoa(shelldata->counter);
	length = _strlen(shelldata->av[0]) + _strlen(ver_str);
	length += _strlen(shelldata->args[0]) + 16;
	err = malloc(sizeof(char) * (length + 1));
	if (err == 0)
	{
		free(err);
		free(ver_str);
		return (NULL);
	}
	_strcpy(err, shelldata->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, shelldata->args[0]);
	_strcat(err, ": not found\n");
	_strcat(err, "\0");
	free(ver_str);
	return (err);
}

/**
 * error_exit_shell - Generic error message for exit in get_exit
 * @shelldata: Data relevant (counter, arguments)
 *
 * Return: Error message
 */
char *error_exit_shell(data_shell *shelldata)
{
	int length;
	char *err;
	char *ver_str;

	ver_str = aux_itoa(shelldata->counter);
	length = _strlen(shelldata->av[0]) + _strlen(ver_str);
	length += _strlen(shelldata->args[0]) + _strlen(shelldata->args[1]) + 23;
	err = malloc(sizeof(char) * (length + 1));
	if (err == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(err, shelldata->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, shelldata->args[0]);
	_strcat(err, ": Illegal number: ");
	_strcat(err, shelldata->args[1]);
	_strcat(err, "\n\0");
	free(ver_str);

	return (err);
}
