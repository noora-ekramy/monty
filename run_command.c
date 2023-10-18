#include "monty.h"
/**
 * get_opcode - Maps an opcode string to its corresponding integer constant.
 * @opcode: The opcode string to be mapped.
 * Return: The corresponding integer constant for the opcode.
 */
int get_opcode(char *opcode)
{
if (strcmp(opcode, "push") == 0)
{
return PUSH;
}
if (strcmp(opcode, "pall") == 0)
{
return PALL;
}
return INVALID_OPCODE;
}
/**
 * run_command - Executes a Monty language command based on the provided arguments.
 * @arguments: An array of strings containing the command and its arguments.
 * Return: 0 on success, exits with EXIT_FAILURE on error.
 */
int run_command(char **arguments)
{
int i = 0;

while (arguments[i] != NULL)
{
printf(" arg %i :%s \n", i,arguments[i]);
i++;
}
if (arguments[0] == NULL)
{
fprintf(stderr, "Error: Empty command\n");
exit(EXIT_FAILURE);
}
char *opcode = arguments[0];

switch (get_opcode(opcode))
{
case PUSH:
push(*stack, arguments[1]);
break;
case PALL:
pall(*stack);
break;
default:
fprintf(stderr, "Error: Unknown instruction: %s\n", opcode);
exit(EXIT_FAILURE);
}
return (0);
}
