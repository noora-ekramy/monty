#include "monty.c"

/**
 * pint - Print the value at the top of the stack, followed by a new line.
 * If the stack is empty, print an error message and exit with EXIT_FAILURE.
 * @line_number: Line number in the Monty file where the pint opcode appears.
 */
int pint(int line_number)
{
	if (globalStack == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		return(EXIT_FAILURE);
	}
	printf("%d\n", globalStack->n);
	return (0);
}
