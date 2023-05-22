#include "main.h"
/**
 * check_env - checks if the typed variable is an env variable
 *
 * @h: head of linked list
 * @in: input string
 * @data: data structure
 * Return: no return
 */
void check_env(r_var **h, char *in, data_shell *data)
{
	char **_envr = data->_environ;
	int row, j;

	for (row = 0; _envr[row]; row++)
	{
		int j = 1, chr = 0;

		while (_envr[row][chr])
		{
			if (_envr[row][chr] == '=')
			{
				int lval = _strlen(_envr[row] + chr + 1);

				add_rvar_node(h, j, _envr[row] + chr + 1, lval);
				return;
			}
			if (in[j] == _envr[row][chr])
				j++;
			else
				break;
			chr++;
		}
	}

for (j = 0; in[j] && in[j] != ' ' && in[j] != '\t'
		&& in[j] != ';' && in[j] != '\n';)
	j++;
add_rvar_node(h, j, NULL, 0);
}

/**
 * check_vars - check if the typed variable is $$ or $?
 *
 * @h: head of the linked list
 * @in: input string
 * @st: last status of the Shell
 * @data: data structure
 * Return: number of characters processed
 */
int check_vars(r_var **h, char *in, char *st, data_shell *data)
{
	int i, lst, lpd;

	lst = _strlen(st);
	lpd = _strlen(data->pid);

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			char nextChar = in[i + 1];

			switch (nextChar)
			{
				case '?':
					add_rvar_node(h, 2, st, lst);
					i++;
					break;
				case '$':
					add_rvar_node(h, 2, data->pid, lpd);
					i++;
					break;
				case '\n':
				case '\0':
				case ' ':
				case '\t':
				case ';':
					add_rvar_node(h, 0, NULL, 0);
					break;
				default:
					check_env(h, in + i, data);
					break;
			}
		}
	}

	return (i);
}

/**
 * replaced_input - replaces variables in a string with their values
 *
 * @head: head of the linked list of variables
 * @input: input string
 * @new_input: new input string with variables replaced
 * @nlen: length of the new input string
 * Return: the new input string
 */
char *replaced_input(r_var **head, char *input, char *new_input, int nlen)
{
	r_var *current_var = *head;
	int input_index = 0;
	int new_input_index = 0;
	int i;

	while (input_index < nlen)
	{
		if (input[input_index] == '$')
		{
			if (!(current_var->len_var) && !(current_var->len_val))
			{
				new_input[new_input_index++] = input[input_index++];
			}
			else if (current_var->len_var && !(current_var->len_val))
			{
				input_index += current_var->len_var;
			}
			else
			{
				for (i = 0; i < current_var->len_val; i++)
				{
					new_input[new_input_index++] = current_var->val[i];
				}
				input_index += (current_var->len_var);
			}
			current_var = current_var->next;
		}
		else
		{
			new_input[new_input_index++] = input[input_index++];
		}
	}
	return (new_input);
}
/**
 * rep_var - replaces variables in input string using data_shell variables
 *
 * @input: input string
 * @datash: data_shell struct containing variables to replace
 * Return: pointer to newly allocated string with variables replaced
 */
char *rep_var(char *input, data_shell *datash)
{
	r_var *vars_head = NULL, *curr_var;
	char *status_str, *new_input;
	int orig_len, new_len;

	status_str = aux_itoa(datash->status);
	orig_len = check_vars(&vars_head, input, status_str, datash);
	if (vars_head == NULL)
	{
		free(status_str);
		return (input);
	}
	curr_var = vars_head;
	new_len = 0;
	while (curr_var != NULL)
	{
		new_len += curr_var->len_val - curr_var->len_var;
		curr_var = curr_var->next;
	}
	new_len += orig_len;
	new_input = malloc(new_len + 1);
	new_input[new_len] = '\0';
	new_input = replaced_input(&vars_head, input, new_input, new_len);
	free(input);
	free(status_str);
	free_rvar_list(&vars_head);
	return (new_input);
}
