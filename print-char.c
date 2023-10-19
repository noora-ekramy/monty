#include "monty.h"
#include <ctype.h>

/**
 * pchar_op - Prints the character at the top of the stack.
 * @line_number: The line number of the current instruction.
 *
 * This function prints the character at the top of the stack,
 * treating it as an ASCII value. If the stack is empty or the
 * value is not a valid ASCII character, it prints an error
 * message to stderr and returns EXIT_FAILURE.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int pchar_op(int line_number)
{
	stack_t *top = stack;

	if (top == NULL)
	{
		fprintf(stderr, "L%i: can't pchar, stack empty\n", line_number);
		return (EXIT_FAILURE);
	}

	if (isascii(top->n))
	{
		putchar(top->n);
		putchar('\n');
		return (EXIT_SUCCESS);
	}

	fprintf(stderr, "L%i: can't pchar, value out of range\n", line_number);
	return (EXIT_FAILURE);
}
