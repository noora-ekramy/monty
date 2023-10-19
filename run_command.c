#include "monty.h"

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
	switch (opcode_to_const(opcode))
	{
	case PUSH:
		exit_code = push(arguments[1], line_num);
		break;
	case PALL:
		pall(stack);
		break;
	case PINT:
		exit_code = pint(line_num);
		break;
	case POP:
		exit_code = pop(line_num);
		break;
	case SWAP:
		exit_code = swap(line_num);
		break;
	case ADD:
		exit_code = add(line_num);
		break;
	case NOP:
		break;
	case SUB:
		exit_code = sub(line_num);
		break;
	case DIV:
		exit_code = div_op(line_num);
		break;
	case MUL:
		exit_code = mul_op(line_num);
		break;
	case MOD:
		exit_code = mod_op(line_num);
		break;
	case PCHAR:
		exit_code = pchar_op(line_num);
		break;
	case PSTR:
		exit_code = pstr_op();
		break;
	default:
		fprintf(stderr, "L%i: unknown instruction %s\n", line_num, opcode);
		return (EXIT_FAILURE);
	}
	return (exit_code);
}
