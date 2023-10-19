#include "monty.h"

stack_t *memStackHead;
stack_t *memStackTail;
int dataStructuer = STACK;
/**
 * main - Entry point for the Monty ByteCodes Interpreter
 *
 * @argc: The number of command-line arguments. It should be 2: the program
 * name and the Monty bytecode file to execute.
 *
 * @argv: An array of command-line arguments, where argv[0] is the program
 * name and argv[1] is the path to the Monty bytecode file to be executed.
 * 
 * Return: The function returns 0 on success. and error num otherwise
 */
int main(int argc, char *argv[])
{
	int exit_stat;

	if (argc != 2)
	{
		fprintf(stderr, "%s\n", "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	exit_stat = read_file(argv[1]);
	free_mem();
	return (exit_stat);
}
