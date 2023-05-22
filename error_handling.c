#include "main.h"
/**
 * get_error - calls the error function according to the error code
 * @shelldata: data structure that includes arguments
 * @eval: error code
 * Return: error code
 */
int get_error(data_shell *shelldata, int eval)
{
	char *error = NULL;

	switch (eval)
	{
		case -1:
			error = error_env(shelldata);
			break;
		case 126:
			error = error_path_126(shelldata);
			break;
		case 127:
			error = error_not_found(shelldata);
			break;
		case 2:
			if (_strcmp(shelldata->args[0], "exit") == 0)
				error = error_exit_shell(shelldata);
			else if (_strcmp(shelldata->args[0], "cd") == 0)
				error = error_get_cd(shelldata);
			break;
	}
	if (error != NULL)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}
	shelldata->status = eval;
	return (eval);
}
