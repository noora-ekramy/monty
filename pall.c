#include "monty.c"

/**
 * pall - Prints all the elements of the stack.
 * @stack: A pointer to the top of the stack.
 * This function prints all the elements of the stack, starting from the top.
 */
void pall(stack_t *stack)
{
	stack_t *current = stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}