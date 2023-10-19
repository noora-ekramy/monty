#include "monty.h"

/**
 * pstr - Prints the string starting from the top of the stack.
 * @line_number: The line number of the current instruction.
 *
 * This function interprets the integers stored in the stack as ASCII values
 * and prints the corresponding characters until it reaches a 0, a non-ASCII
 * character, or the stack is empty. If the stack is empty, it prints only
 * a new line.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int pstr()
{
	stack_t *current = stack;

	while (current != NULL && current->n != 0 && isascii(current->n))
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');


	return (EXIT_SUCCESS);
}
