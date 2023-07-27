#include "monty.h"
/**
 * monty_add - add two top values
 * @stack: pointer to top
 * @line_num: line number
 */
void monty_add(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_num, "add"));
		return;
	}
	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_num);
}
/**
 * monty_sub - subtract second value from top
 * @stack: top of stack
 * @line_num: line number
 */
void monty_sub(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_num, "sub"));
		return;
		(*stack)->next->next->n -= (*stack)->next->n;
		monty_pop(stack, line_num);
	}
}
/**
 * monty_div - divide second value from top
 * @stack: pointer to top
 * @line_num: line number
 */
void monty_div(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_num, "div"));
		return;
	}
	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_num));
		return;
	}
	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_num);
}
/**
 * monty_mul - multiply top 2 values
 * @stack: pointer to top
 * @line_num: line number
 */
void monty_mul(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_num, "mul"));
		return;
	}
	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_num);
}
/**
 * monty_mod - modulus of second from top
 * @stack: pointer to top
 * @line_num: line number
 */
void monty_mod(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_num, "mod"));
		return;
	}
	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_num));
		return;
	}
	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_num);
}
