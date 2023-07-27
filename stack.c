#include "monty.h"
#include <string.h>

/**
 * free_stack - free stack
 * @stack: pointer to top of stack
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
/**
 * init_stack - initialize stack
 * @stack: pointer to top
 * Return: exit failure or success
 */
int init_stack(stack_t **stack)
{
	stack_t *r;

	r = malloc(sizeof(stack_t));
	if (r == NULL)
		return (malloc_error());

	r->n = STACK;
	r->prev = NULL;
	r->next = NULL;
	*stack = r;
	return (EXIT_SUCCESS);
}
/**
 * check_mode - check if list is stack or queue
 * @stack: pointer to top
 * Return: 0 for stack 1 for queue and 2 otherwise
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
