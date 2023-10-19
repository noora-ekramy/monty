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
    int i = 0;

    int myArray[1024];
	if (top == NULL)
		return (EXIT_SUCCESS);

    myArray[i] = top->n;
    

	while (top->next != NULL)
    {
        i++;
		myArray[i] = top->next->n;
        top = top->next;
    }

    i = 0;
    top->n = myArray[i];
    while (top->prev != NULL)
    {
        i++;
		top->prev->n = myArray[i];
        top = top->prev;
    }
	return (EXIT_SUCCESS);
}