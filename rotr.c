#include "monty.h"
/**
 * rotr_op - Rotates the stack to the bottom.
 * @line_number: The line number of the current instruction.
 *
 * This function rotates the stack to the bottom, where the last element
 * becomes the top element, and all other elements shift down. It does so
 * by adjusting the pointers of the stack nodes accordingly.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int rotr_op()
{
	stack_t *last = globalStack;
	stack_t *secondLast = NULL;

	if (last == NULL || last->next == NULL)
		return (EXIT_SUCCESS);

	while (last->next != NULL)
	{
		secondLast = last;
		last = last->next;
	}
	secondLast->next = NULL;
	last->next = globalStack;
	last->prev = NULL;

	if (globalStack != NULL)
		globalStack->prev = last;
	globalStack = last;

	return (EXIT_SUCCESS);
}
