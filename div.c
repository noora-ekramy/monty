#include "monty.h"

/**
 * div_op - Divides the second top element of the stack by the top element.
 * @line_number: The line number of the current instruction.
 *
 * This function divides the second top element of the stack by the top element
 * and replaces the second top node with the result. If the stack does not have
 * at least two elements or if the top element is 0, it prints an error message
 * to stderr and returns EXIT_FAILURE.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int div_op(unsigned int line_number)
{
    int result;
    stack_t *top = stack;

    if (top == NULL || top->next == NULL)
    {
        fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
        return (EXIT_FAILURE);
    }

    if (top->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        return (EXIT_FAILURE);
    }

    result = top->next->n / top->n;
    top->next->n = result;

    top->next->prev = NULL;
    stack = top->next;
    free(top);

    return (EXIT_SUCCESS);
}