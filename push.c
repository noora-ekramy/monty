#include "monty.h"

/**
 * push - Pushes an integer onto the stack.
 * @stack: A pointer to the top of the stack.
 * @str_value: The string representation of the
 * integer to be pushed onto the stack.
 * This function converts the string representation
 * of an integer to an actual integer
 * and pushes it onto the stack.
 */
int push(char *str_value, int line_num)
{
	int value;
	stack_t *new_node;

	if (str_value == NULL || is_integer(str_value) == 0)
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_num);
		return(EXIT_FAILURE);
	}

	value = atoi(str_value);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	if (globalStack)
	{
		new_node->next = globalStack;
		(globalStack)->prev = new_node;
	}
	else
	{
		new_node->next = NULL;
	}

	globalStack = new_node;
	return(0);
}
