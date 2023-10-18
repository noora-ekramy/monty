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
void push(char *str_value)
{
	int value;
	stack_t *new_node;

	if (str_value == NULL)
	{
		fprintf(stderr, "Error: usage: push integer\n");
		exit(EXIT_FAILURE);
	}

	value = atoi(str_value);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
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
}
/**
 * pall - Prints all the elements of the stack.
 * @stack: A pointer to the top of the stack.
 * This function prints all the elements of the stack, starting from the top.
 */
void pall(stack_t *stack)
{
	stack_t *current = stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * free_stack - Frees the memory allocated for a stack.
 * @stack: A pointer to the head of the stack.
 * This function frees the memory allocated for all nodes in the stack. It
 * iterates through the stack, frees each node, and updates the stack pointer
 * to indicate an empty stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *temp;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

