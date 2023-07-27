#include "monty.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * free_tokens - free op_toks
 */
void free_tokens(void)
{
	size_t x = 0;

	if (op_toks == NULL)
		return;
	for (x = 0; op_toks[x]; x++)
		free(op_toks[x]);
	free(op_toks);

}
/**
 * token_arr_len - get token length
 * Return: length of op_toks
 */
unsigned int token_arr_len(void)
{
	unsigned int toks_len = 0;

	while (op_toks[toks_len])
		toks_len++;
	return (toks_len);
}
/**
 * is_empty_line - check if only delimiters
 * @line: line
 * @delims: string of delimiters
 * Return: 1 for only delimiters 0 otherwise
 */
int is_empty_line(char *line, char *delims)
{
	int x, y;

	for (x = 0; line[x]; x++)
	{
		for (y = 0; delims[y]; y++)
		{
			if (line[x] == delims[y])
				break;
		}
		if (delims[y] == '\0')
			return (0);
	}
	return (1);
}
/**
 * get_op_func - match opcode
 * @opcode: opcode to match
 * Return: pointer to corresponding funtion
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"stack", monty_stack},
		{"queue", monty_queue},
		{NULL, NULL}
	};
	int x;

	for (x = 0; op_funcs[x].opcode; x++)
	{
		if (strcmp(opcode, op_funcs[x].opcode) == 0)
			return (op_funcs[x].f);
	}
	return (NULL);
}
/**
 * run_monty - primary monty function
 * @script_fd: file descriptor
 * Return: exit success or failure
 */
int run_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_num = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (fgets(line, (int)(len), script_fd) != NULL)
	{
		line_num++;
		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			free_stack(&stack);
			return (malloc_error());
		}
		else if (op_toks[0][0] == '#')
		{
			free_tokens();
			continue;
		}
		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			exit_status = unknown_op_error(op_toks[0], line_num);
			free_tokens();
			break;
		}
		prev_tok_len = token_arr_len();
		op_func(&stack, line_num);
		if (token_arr_len() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	free_stack(&stack);
	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}
	free(line);
	return (exit_status);
}
