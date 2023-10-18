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
		return (PUSH);
	}
	if (strcmp(opcode, "pall") == 0)
	{
		return (PALL);
	}
	return (INVALID_OPCODE);
}
/**
 * run_command - Executes a Monty language command based
 * on the provided arguments.
 * @arguments: An array of strings containing the command and its arguments.
 * Return: 0 on success, exits with EXIT_FAILURE on error.
 */
int run_command(char **arguments, int line_num)
{
	char *opcode;
	if (arguments[0] == NULL)
	{
		return (EXIT_FAILURE);
	}
	opcode = arguments[0];
	switch (get_opcode(opcode))
	{
		case PUSH:
			push(arguments[1], line_num);
			break;
		case PALL:
			pall(globalStack);
			break;
		default:
			fprintf(stderr, "L%i: unknown instruction %s\n", line_num , opcode);
			exit(EXIT_FAILURE);
	}
	return (0);
}
