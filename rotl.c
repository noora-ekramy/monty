#include "monty.h"

/**
 * rotl_op - Rotates the stack to the top.
 * @line_number: The line number of the current instruction.
 *
 * This function rotates the stack to the top, where the top element becomes
 * the last one, and the second top element becomes the first one. It does so
 * by adjusting the pointers of the stack nodes accordingly.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int rotl_op()
{
	stack_t *top = globalStack;
	stack_t *second = NULL;

	if (top == NULL || top->next == NULL)
		return (EXIT_SUCCESS);

	second = top->next;
	while (second->next != NULL)
		second = second->next;

	second->next = top;
    globalStack = top->next;
	top->prev = second;
	top->next = NULL;

	return (EXIT_SUCCESS);
}