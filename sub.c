#include "monty.h"

/**
 * add - subtracts top two elements of the stack, pops them, and pushes the sum.
 * @line_number: The line number of the current instruction.
 *
 * This function subtracts the top two elements of the stack represented by the
 * globalStack and replaces the top node with the sum. If the stack does not
 * have at least two elements, it prints an error message to stderr and
 * returns EXIT_FAILURE.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int sub(int line_number)
{
	int sum;
	stack_t *top = globalStack;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%i: can't sub, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}


	sum = top->n;
	sum = top->next->n - sum;
	top->next->n = sum;

	top->next->prev = NULL;
	globalStack = top->next;
	free(top);

	return (EXIT_SUCCESS);
}