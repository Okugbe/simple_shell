#include "main.h"

/**
 * repeated_char - Counts the repetitions of a char
 *
 * @input: input string
 * @index: index
 * Return: repetitions
 */
int repeated_char(char *input, int index)
{
	if (*(input - 1) == *input)
		return (repeated_char(input - 1, index + 1));

	return (index);
}

/**
 * error_sep_op - Finds syntax errors
 *
 * @input: input string
 * @index: index
 * @last: last char read
 * Return: index of error. 0 when there are no
 * errors
 */
int error_sep_op(char *input, int index, char last)
{
	int counter;

	counter = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (error_sep_op(input + 1, index + 1, last));

	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (index);

	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (index);

		if (last == '|')
		{
			counter = repeated_char(input, 0);
			if (counter == 0 || counter > 1)
				return (index);
		}
	}

	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (index);

		if (last == '&')
		{
			counter = repeated_char(input, 0);
			if (counter == 0 || counter > 1)
				return (index);
		}
	}

	return (error_sep_op(input + 1, index + 1, *input));
}

/**
 * first_char - finds index of the first char
 *
 * @input: input string
 * @index: index
 * Return: 1 if there is an error. 0 in other case.
 */
int first_char(char *input, int *index)
{

	for (*index = 0; input[*index]; *index += 1)
	{
		if (input[*index] == ' ' || input[*index] == '\t')
			continue;

		if (input[*index] == ';' || input[*index] == '|' || input[*index] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * print_syntax_error - prints when a syntax error is found
 *
 * @datast: data structure
 * @input: input string
 * @index: index of the error
 * @bool: to control msg error
 * Return: no return
 */
void print_syntax_error(data_shell *datast, char *input, int index, int bool)
{
	char *msg, *msg2, *msg3, *err, *counter;
	int length;

	if (input[index] == ';')
	{
		if (bool == 0)
			msg = (input[index + 1] == ';' ? ";;" : ";");
		else
			msg = (input[index - 1] == ';' ? ";;" : ";");
	}

	if (input[index] == '|')
		msg = (input[index + 1] == '|' ? "||" : "|");

	if (input[index] == '&')
		msg = (input[index + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	counter = aux_itoa(datast->counter);
	length = _strlen(datast->av[0]) + _strlen(counter);
	length += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

	err = malloc(sizeof(char) * (length + 1));
	if (err == 0)
	{
		free(counter);
		return;
	}
	_strcpy(err, datast->av[0]);
	_strcat(err, ": ");
	_strcat(err, counter);
	_strcat(err, msg2);
	_strcat(err, msg);
	_strcat(err, msg3);
	_strcat(err, "\0");

	write(STDERR_FILENO, err, length);
	free(err);
	free(counter);
}

/**
 * check_syntax_error - intermediate function to
 * find and print a syntax error
 *
 * @datast: data structure
 * @input: input string
 * Return: 1 if there is an error. 0 in other case
 */
int check_syntax_error(data_shell *datast, char *input)
{
	int begin = 0;
	int f_char = 0;
	int i = 0;

	f_char = first_char(input, &begin);
	if (f_char == -1)
	{
		print_syntax_error(datast, input, begin, 0);
		return (1);
	}

	i = error_sep_op(input + begin, 0, *(input + begin));
	if (i != 0)
	{
		print_syntax_error(datast, input, begin + i, 1);
		return (1);
	}

	return (0);
}

