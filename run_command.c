#include "monty.h"

/**
 * run_command_complement - Execute the rest of Monty bytecode commands.
 * @arguments: An array of strings containing command arguments.
 * @line_number: The line number of the current Monty bytecode instruction.
 *
 * Return: Nothing.
 */
void run_command_complement(char **arguments, int line_number)
{
	unsigned short int opcode_const;

	opcode_const = opcode_to_const(arguments[0]);

	switch (opcode_const)
	{
	case ADD:
		add(line_number);
		break;
	case SUB:
		sub(line_number);
		break;
	case MUL:
		mul(line_number);
		break;
	case DIV:
		div_op(line_number);
		break;
	case MOD:
		mod(line_number);
		break;
	default:
		fprintf(stderr, "L%i: unknown instruction %s\n", line_number, arguments[0]);
		free_stack();
		exit(EXIT_FAILURE);
	}
}

/**
 * run_command - Execute a Monty bytecode command.
 * @arguments: An array of strings containing command arguments.
 * @line_number: The line number of the current Monty bytecode instruction.
 *
 * Return: Nothing.
 */
void run_command(char **arguments, int line_number)
{
	unsigned short int opcode_const;

	if (arguments[0] == NULL)
		exit(EXIT_FAILURE);

	opcode_const = opcode_to_const(arguments[0]);

	switch (opcode_const)
	{
	case PUSH:
		push(arguments[1], line_number);
		break;
	case POP:
		pop(line_number);
		break;
	case PINT:
		pint(line_number);
		break;
	case PCHAR:
		pchar(line_number);
		break;
	case PSTR:
		pstr();
		break;
	case PALL:
		pall(stack);
		break;
	case SWAP:
		swap(line_number);
		break;
	case NOP:
		break;
	default:
		run_command_complement(arguments, line_number);
	}
}
