#include "monty.h"
/**
 * pop_error - pop error message
 * @line_num: line number
 * Return: exit failure
 */
int pop_error(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
	return (EXIT_FAILURE);
}
/**
 * pint_error - pint error for empty stack
 * @line_num: line number
 * Return: exit failure
 */
int pint_error(unsigned int line_num)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
	return (EXIT_FAILURE);
}
/**
 * short_stack_error - smaller than 2 nodes
 * @line_num: line number
 * @op: operation
 * Return: exit failure
 */
int short_stack_error(unsigned int line_num, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_num, op);
	return (EXIT_FAILURE);
}
/**
 * div_error - print div error
 * @line_num: line number
 * Return: exit failure
 */
int div_error(unsigned int line_num)
{
	fprintf(stderr, "L%u: division by zero\n", line_num);
	return (EXIT_FAILURE);
}
/**
 * pchar_error - error for empty stack and non-char values
 * @line_num: line number
 * @message: error message
 * Return: exit failure
 */
int pchar_error(unsigned int line_num, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_num, message);
	return (EXIT_FAILURE);
}
