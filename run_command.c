#include "monty.h"

/**
 * run_command_complement - Execute the rest of Monty bytecode commands.
 * @arguments: An array of strings containing command arguments.
 * @line_number: The line number of the current Monty bytecode instruction.
 *
 * Return: Nothing.
 */
void run_command_complement(char **arguments, unsigned int line_number)
{
	char *argument;
	short int exit_code = EXIT_SUCCESS;

	switch (opcode_to_const(arguments[0]))
	{
	case ADD:
		exit_code = add(line_number);
		break;
	case SUB:
		exit_code = sub(line_number);
		break;
	case MUL:
		exit_code = mul(line_number);
		break;
	case DIV:
		exit_code = div_op(line_number);
		break;
	case MOD:
		exit_code = mod(line_number);
		break;
	default:
		fprintf(stderr, "L%i: unknown instruction %s\n", line_number, arguments[0]);
		free_stack();
		exit(EXIT_FAILURE);
	}

	if (exit_code == EXIT_FAILURE)
	{
		for (argument = *arguments; argument; argument++)
			free(argument);

		free(arguments);
		free_stack();
	}
}

/**
 * run_command - Execute a Monty bytecode command.
 * @arguments: An array of strings containing command arguments.
 * @line_number: The line number of the current Monty bytecode instruction.
 *
 * Return: Nothing.
 */
void run_command(char **arguments, unsigned int line_number)
{
	char *argument;
	short int exit_code = EXIT_SUCCESS;

	if (arguments[0] == NULL)
		exit(EXIT_FAILURE);
	switch (opcode_to_const(arguments[0]))
	{
	case PUSH:
		exit_code = (arguments[1], line_number);
		break;
	case POP:
		exit_code = pop(line_number);
		break;
	case PINT:
		exit_code = pint(line_number);
		break;
	case PCHAR:
		exit_code = pchar(line_number);
		break;
	case PSTR:
		exit_code = pstr();
		break;
	case PALL:
		pall();
		break;
	case SWAP:
		exit_code = swap(line_number);
		break;
	case NOP:
		break;
	default:
		run_command_complement(arguments, line_number);
	}
	if (exit_code == EXIT_FAILURE)
	{
		for (argument = *arguments; argument; argument++)
			free(argument);
		free(arguments);
		free_stack();
	}
}
