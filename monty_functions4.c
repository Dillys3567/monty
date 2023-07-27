#include "monty.h"
/**
 * monty_rotl - rotate top value
 * @stack: pointer to top
 * @line_num: line number
 */
void monty_rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;
	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;
	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev =  bottom;
	(void)line_num;
}
/**
 * monty_rotr - rotate top
 * @stack: pointer to top
 * @line_num: line number
 */
void monty_rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;
	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;
	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;
	(void)line_num;
}
/**
 * monty_stack - convert queue to stack
 * @stack: pointer to top
 * @line_num: line number
 */
void monty_stack(stack_t **stack, unsigned int line_num)
{
	(*stack)->n = STACK;
	(void)line_num;
}
/**
 * monty_queue - stack to queue
 * @stack: pointer to top
 * @line_num: line number
 */
void monty_queue(stack_t **stack, unsigned int line_num)
{
	(*stack)->n = QUEUE;
	(void)line_num;
}
