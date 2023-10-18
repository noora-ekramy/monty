#include "monty.h"
/**
 * push - Pushes an integer onto the stack.
 * @stack: A pointer to the top of the stack.
 * @str_value: The string representation of the integer to be pushed onto the stack.
 * This function converts the string representation of an integer to an actual integer
 * and pushes it onto the stack.
 */
void push(stack_t **stack, char *str_value)
{
int value;
stack_t *new_node;
if (str_value == NULL || !is_integer(str_value))
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

if (*stack)
{
new_node->next = *stack;
(*stack)->prev = new_node;
}
else
{
new_node->next = NULL;
}

*stack = new_node;
}
/**
 * pall - Prints all the elements of the stack.
 * @stack: A pointer to the top of the stack.
 * This function prints all the elements of the stack, starting from the top.
 */
void pall(stack_t **stack)
{
stack_t *current = *stack;

while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}
