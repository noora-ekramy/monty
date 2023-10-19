#include "monty.h"

/**
 * free_stack - Frees the memory allocated for a stack.
 * @stack: A pointer to the head of the stack.
 * This function frees the memory allocated for all nodes in the stack. It
 * iterates through the stack, frees each node, and updates the stack pointer
 * to indicate an empty stack.
 */
void free_stack()
{
	stack_t *current = globalStack;
	stack_t *temp;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}
