#include "monty.h"

/**
 * add - Adds top two elements of stack, pops them, and pushes the sum.
 * @line_number: The line number of the current instruction.
 *
 * This function adds the top two elements of the stack represented by the
 * stack and replaces the top node with the sum. If the stack does not
 * have at least two elements, it prints an error message to stderr and
 * returns EXIT_FAILURE.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int add(int line_number)
{
	int sum;
	stack_t *top = stack;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	sum = top->n;
	sum += top->next->n;
	top->next->n = sum;

	top->next->prev = NULL;
	stack = top->next;
	free(top);

	return (EXIT_SUCCESS);
}
