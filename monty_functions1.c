#include "monty.h"
/**
 * monty_push - push to stack
 * @stack: pointer to top of stack
 * @line_num: line number
 */
void monty_push(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp, *new;
	int x;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}
	if (op_toks[1] == NULL)
	{
		set_op_tok_error(int_error(line_num));
		return;
	}
	for (x = 0; op_toks[1][x]; x++)
	{
		if (op_toks[1][x] == '-' && x == 0)
			continue;
		if (op_toks[1][x] < '0' || op_toks[1][x] > '9')
		{
			set_op_tok_error(int_error(line_num));
			return;
		}
	}
	new->n = atoi(op_toks[1]);
	if (check_mode(*stack) == STACK)
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev =  tmp;
		new->next = NULL;
		tmp->next = new;
	}
}
/**
 * monty_pall - print stack values
 * @stack: pointe to top
 * @line_num: current line
 */
void monty_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(voif)line_num;
}
/**
 * monty_pint -  print top value
 * @stack: pointer to top
 * @line_num: line number
 */
void monty_pint(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(line_num));
		return;
	}
	printf("%d\n", (*stack)->next->n);
}
/**
 * monty_pop - remove top value
 * @stack: pointer to top
 * @line_num: line number
 */
void monty_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pop_error(line_num));
		return;
	}
	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}
/**
 * monty_swap - swap two top values
 * @stack: pointer to top
 * @line_num: line number
 */
void monty_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_num, "swap"));
		return;
	}
	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
