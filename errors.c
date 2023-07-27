#include "monty.h"
/**
 * use_error - print usage error messages
 * Return: exit failure
 */
int use_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}
/**
 * malloc_error - malloc error
 * Return: exit failure
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
/**
 * open_errors - file open error
 * @file: filename
 * Return: exit failure
 */
int open_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	return (EXIT_FAILURE);
}
/**
 * unknown_op_error - unknown op code
 * @opcode: opcode
 * @line_num: line number
 * Return: exit_failure
 */
int unknown_op_error(char *opcode, unsigned int line_num)
{
	fprintf(stderr, "L%u: unknown instruction %s\n"
			, line_num, opcode);
	return (EXIT_FAILURE);
}
/**
 * int_error - invalid monty push
 * @line_num: line number
 * Return: exit failure
 */
int int_error(unsigned int line_num)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_num);
	return (EXIT_FAILURE);
}
