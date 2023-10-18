#include "monty.h"
/**
 * get_opcode - Maps an opcode string to its corresponding integer constant.
 * @opcode: The opcode string to be mapped.
 * Return: The corresponding integer constant for the opcode.
 */
int get_opcode(char *opcode)
{
	if (strcmp(opcode, "push") == 0)
		return (PUSH);
	if (strcmp(opcode, "pall") == 0)
		return (PALL);
	if (strcmp(opcode, "pint") == 0)
		return (PINT);
	if (strcmp(opcode, "pop") == 0)
		return (POP);

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
	int exit_code;

	if (arguments[0] == NULL)
	{
		return (0);
	}
	exit_code = 0;
	opcode = arguments[0];
	switch (get_opcode(opcode))
	{
	case PUSH:
		exit_code = push(arguments[1], line_num);
		break;
	case PALL:
		pall(globalStack);
		break;
	case PINT:
		exit_code = pint(line_num);
		break;
	case POP:
		exit_code = pop(line_num);
		break;
	case SWAP:
		break;
	case ADD:
		break;
	case NOP:
		break;
	default:
		fprintf(stderr, "L%i: unknown instruction %s\n", line_num, opcode);

		return (EXIT_FAILURE);
	}
	return (exit_code);
}
