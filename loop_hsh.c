#include "main.h"

/**
 * without_comment - Deletes comments from the input
 *
 * @rin: input string
 * Return: input without comments
 */
char *without_comment(char *rin)
{
int i, up_to;

up_to = 0;
for (i = 0; rin[i]; i++)
{
if (rin[i] == '#')
{
	if (i == 0)
	{
		free(rin);
		return (NULL);
	}
	if (rin[i - 1] == ' ' || rin[i - 1] == '\t' || rin[i - 1] == ';')
		up_to = i;
	}
}
if (up_to != 0)
{
rin = _realloc(rin, i, up_to + 1);
rin[up_to] = '\0';
}
return (rin);
}

/**
 * shell_loop - Loop of shell
 * @shelldata: data relevant (av, input, args)
 *
 * Return: no return.
 */
void shell_loop(data_shell *shelldata)
{
int i_eof;
char *input;

while (1)
{
write(STDIN_FILENO, "$ ", 4);
input = read_line(&i_eof);
if (i_eof == -1)
{
	free(input);
	break;
}
input = without_comment(input);
if (input == NULL)
	continue;
if (check_syntax_error(shelldata, input) == 1)
{
	shelldata->status = 2;
	free(input);
	continue;
}
input = rep_var(input, shelldata);
split_commands(shelldata, input);
shelldata->counter += 1;
free(input);
}
}


