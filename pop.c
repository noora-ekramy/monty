#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * If the stack is empty, print an error message and exit with EXIT_FAILURE.
 * @line_number: Line number in the Monty file where the pop opcode appears.
 */
int pop(unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		return(EXIT_FAILURE);
	}

	temp = stack;
	stack = stack->next;

	if (stack != NULL)
	{
		stack->prev = NULL;
	}

	free(temp);
	return (0);
}