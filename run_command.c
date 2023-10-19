#include "monty.h"
/**
 * get_opcode - Maps an opcode string to its corresponding integer constant.
 * @opcode: The opcode string to be mapped.
 * Return: The corresponding integer constant for the opcode.
 */
int get_opcode(char *opcode)
{
	char *p;

	for (p = opcode; *p; ++p)
		*p = tolower(*p);

	if (strcmp(opcode, "push") == 0)
		return (PUSH);
	if (strcmp(opcode, "pall") == 0)
		return (PALL);
	if (strcmp(opcode, "pint") == 0)
		return (PINT);
	if (strcmp(opcode, "pop") == 0)
		return (POP);
	if (strcmp(opcode, "swap") == 0)
		return (SWAP);
	if (strcmp(opcode, "add") == 0)
		return (ADD);
	if (strcmp(opcode, "nop") == 0 || opcode[0] == '#')
		return (NOP);
	if (strcmp(opcode, "sub") == 0)
		return (SUB);
	if (strcmp(opcode, "div") == 0)
		return (DIV);
	if (strcmp(opcode, "mul") == 0)
		return (MUL);
	if (strcmp(opcode, "mod") == 0)
		return (MOD);
	if (strcmp(opcode, "pchar") == 0)
		return (PCHAR);
	if (strcmp(opcode, "pstr") == 0)
		return (PSTR);
	if (strcmp(opcode, "rotl") == 0)
		return (ROTL);
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
	case ROTL:
		exit_code = rotl_op();
		break;
	default:
		fprintf(stderr, "L%i: unknown instruction %s\n", line_num, opcode);
		return (EXIT_FAILURE);
	}
	return (exit_code);
}
