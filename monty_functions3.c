#include "monty.h"
/**
 * monty_nop - do nothing
 * @stack: pointer to top
 * @line_num: line number
 */
void monty_nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}
/**
 * monty_pchar - print char at top
 * @stack: pointer to top
 * @line_num: line number
 */
void monty_pchar(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_num, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(pchar_error(line_num
					, "value out of range"));
		return;
	}
	printf("%c\n", (*stack)->next->n);
}
/**
 * monty_pstr - print string
 * @stack: pointer to top
 * @line_num: line number
 */
void monty_pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
	(void)line_num;
}
