#include "monty.h"
/**
 * runbasic_op - Executes basic stack operations based on the provided opcode.
 * @function: The opcode to be executed (e.g., "push", "pall", "pint", "pop").
 * @lineNum: The line number of the current opcode in the input file.
 * @arguments: An array of strings containing arguments associated with the opcode.
 *
 * This function interprets the given opcode and performs the corresponding
 * operation on the stack. It supports basic stack operations like push, pop,
 * pall, and pint. If the opcode is valid and the operation is successful, the
 * function returns 0; otherwise, it returns a non-zero exit code.
 *
 * @function must be one of the following:
 *   - "push": Pushes the integer value specified in @arguments[1] onto the stack.
 *   - "pall": Prints all the values on the stack, starting from the top.
 *   - "pint": Prints the value at the top of the stack.
 *   - "pop": Removes the top element of the stack.
 *
 * @lineNum: The line number in the input file where the opcode appears.
 * @arguments: An array of strings containing the arguments for the opcode.
 *              - For "push" opcode, arguments[1] should contain the integer value to be pushed.
 *              - For other opcodes, arguments can be NULL or ignored.
 *
 * Return: 0 on successful execution of the opcode, non-zero on failure.
 *         - For push, non-zero indicates failure to push the value onto the stack.
 *         - For pint and pop, non-zero indicates an empty stack error.
 *         - For other opcodes, non-zero indicates an invalid or unsupported opcode error.
 */
int runbasic_op(char *function, int lineNum, char **arguments)
{
    int exit_code = 0;

    if (strcmp(function, "push") == 0)
        exit_code = push(arguments[1], lineNum);
    if (strcmp(function, "pall") == 0)
        pall();
    if (strcmp(function, "pint") == 0)
        exit_code = pint(lineNum);
    if (strcmp(function, "pop") == 0)
        exit_code = pop(lineNum);

    return (exit_code);
}

/**
 * free_stack - Frees the memory allocated for a stack.
 * @stack: A pointer to the head of the stack.
 * This function frees the memory allocated for all nodes in the stack. It
 * iterates through the stack, frees each node, and updates the stack pointer
 * to indicate an empty stack.
 */
void free_mem()
{
    stack_t *current = memStackHead;
    stack_t *temp;

    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
}

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
        return (EXIT_FAILURE);
    }

    value = atoi(str_value);
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        return (EXIT_FAILURE);
    }

    new_node->n = value;
    if (dataStructuer == STACK)
    {
        new_node->prev = NULL;
        if (memStackHead)
        {
            new_node->next = memStackHead;
            (memStackHead)->prev = new_node;
        }
        else
        {
            new_node->next = NULL;
            memStackTail = new_node;
        }

        memStackHead = new_node;
    }
    else
    {
        new_node->next = NULL;
        if (memStackTail)
        {
            new_node->prev = memStackTail;
            (memStackTail)->next = new_node;
        }
        else
        {
            new_node->prev = NULL;
            memStackHead = new_node;
        }
        memStackTail = new_node;
    }
    return (0);
}

/**
 * pall - Prints all the elements of the stack.
 * @stack: A pointer to the top of the stack.
 * This function prints all the elements of the stack, starting from the top.
 */
void pall()
{
    stack_t *current;

    current = memStackHead;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }

}

/**
 * pint - Print the value at the top of the stack, followed by a new line.
 * If the stack is empty, print an error message and exit with EXIT_FAILURE.
 * @line_number: Line number in the Monty file where the pint opcode appears.
 */
int pint(int line_number)
{
    if (dataStructuer == STACK)
    {
        if (memStackHead == NULL)
        {
            fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
            return (EXIT_FAILURE);
        }
        printf("%d\n", memStackHead->n);
    }
    else
    {
        if (memStackTail == NULL)
        {
            fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
            return (EXIT_FAILURE);
        }
        printf("%d\n", memStackTail->n);        
    }

    return (0);
}
/**
 * pop - Removes the top element of the stack.
 * If the stack is empty, print an error message and exit with EXIT_FAILURE.
 * @line_number: Line number in the Monty file where the pop opcode appears.
 */
int pop(unsigned int line_number)
{
	stack_t *temp;

    if (dataStructuer == STACK)
    {
        if (memStackHead == NULL)
        {
            fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
            return(EXIT_FAILURE);
        }

        temp = memStackHead;
        memStackHead = memStackHead->next;

        if (memStackHead != NULL)
        {
            memStackHead->prev = NULL;
        }

        free(temp);
    }
    else
    {
        if (memStackTail == NULL)
        {
            fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
            return(EXIT_FAILURE);
        }

        temp = memStackTail;
        memStackTail = memStackTail->prev;

        if (memStackTail != NULL)
        {
            memStackTail->next = NULL;
        }

        free(temp);
    }
	return (0);
}