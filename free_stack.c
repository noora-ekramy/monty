#include "monty.h"

/**
 * free_stack - Frees the memory allocated for the stack.
 *
 * Description: This function frees memory allocated for all nodes in stack.
 * It iterates through the stack, frees each node, and updates the stack
 * pointer to indicate an empty stack.
 *
 * Return: Nothing.
 */
void free_stack(void)
{
	stack_t *top;

	while (stack != NULL)
	{
		top = stack;
		stack = stack->next;
		free(top);
	}
}
