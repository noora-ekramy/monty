#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @line_number: The line number of the current instruction.
 *
 * Description: This function swaps the top two elements of the stack
 * represented by the globalStack. If the stack does not have at least
 * two elements, it prints an error message to stderr and returns EXIT_FAILURE.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int swap(int line_number)
{
	int temp;
	stack_t *top = globalStack;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	temp = top->n;
	top->n = top->next->n;
	top->next->n = temp;

	return (EXIT_SUCCESS);
}
