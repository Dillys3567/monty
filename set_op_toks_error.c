#include "monty.h"
/**
 * set_op_tok_error - set last element to be error code
 * @error_code: int to store as string
 */
void set_op_tok_error(int error_code)
{
	int toks_len = 0, x = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = token_arr_len();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!op_toks)
	{
		malloc_error();
		return;
	}
	while (x < toks_len)
	{
		new_toks[x] = op_toks[x];
		x++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		free(new_toks);
		malloc_error();
		return;
	}
	new_toks[x++] = exit_str;
	new_toks[x] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
