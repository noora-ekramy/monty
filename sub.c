#include "monty.h"

/**
 * add - Subtracts top two elements of stack, pops them, and pushes the difference.
 * @line_number: The line number of the current instruction.
 *
 * This function subtracts the top two elements of the stack represented by the
 * globalStack and replaces the top node with the difference. If the stack does
 * not have at least two elements, it prints an error message to stderr and
 * returns EXIT_FAILURE.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int sub(int line_number)
{
	int difference;
	stack_t *top = stack;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%i: can't sub, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	difference = top->n;
	difference = top->next->n - difference;
	top->next->n = difference;

	top->next->prev = NULL;
	stack = top->next;
	free(top);

	return (EXIT_SUCCESS);
}
