#include "monty.h"

/**
 * add - Adds top two elements of the stack, pops them, and pushes the sum.
 * @line_number: The line number of the current instruction.
 *
 * This function adds the top two elements of the stack represented by the
 * globalStack and replaces the top node with the sum. If the stack does not
 * have at least two elements, it prints an error message to stderr and
 * returns EXIT_FAILURE.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int add(int line_number)
{
	int sum;
	stack_t *top = memStackHead;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	sum = top->n;
	sum += top->next->n;
	top->next->n = sum;

	top->next->prev = NULL;
	memStackHead = top->next;
	free(top);

	return (EXIT_SUCCESS);
}


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
    stack_t *top = memStackHead;

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
    memStackHead = top->next;
    free(top);

    return (EXIT_SUCCESS);
}

/**
 * mod_op - Computes the rest of the division of the second top element of
 *          the stack by the top element.
 * @line_number: The line number of the current instruction.
 *
 * This function computes the rest of the division of the second top element
 * of the stack by the top element and replaces the second top node with the
 * result. If the stack does not have at least two elements or if the top
 * element is 0, it prints the appropriate error message to stderr and
 * returns EXIT_FAILURE.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */

int mod_op(unsigned int line_number)
{
	int result;
	stack_t *top = memStackHead;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		return (EXIT_FAILURE);
	}

	result = top->next->n % top->n;
	top->next->n = result;

	top->next->prev = NULL;
	memStackHead = top->next;
	free(top);

	return (EXIT_SUCCESS);
}


/**
 * mul_op - Multiplies the second top element of the stack by the top element.
 * @line_number: The line number of the current instruction.
 *
 * This function multiplies the second top element of the stack by the top
 * element and replaces the second top node with the result. If the stack does
 * not have at least two elements, it prints an error message to stderr and
 * returns EXIT_FAILURE.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int mul_op(unsigned int line_number)
{
	int result;
	stack_t *top = memStackHead;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	result = top->next->n * top->n;
	top->next->n = result;

	top->next->prev = NULL;
	memStackHead = top->next;
	free(top);

	return (EXIT_SUCCESS);
}


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
	stack_t *top = memStackHead;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%i: can't sub, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}


	sum = top->n;
	sum = top->next->n - sum;
	top->next->n = sum;

	top->next->prev = NULL;
	memStackHead = top->next;
	free(top);

	return (EXIT_SUCCESS);
}
