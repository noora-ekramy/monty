#include "monty.h"
stack_t *globalStack = NULL;
/**
 * main - entry point to monty
 *
 * @argc: argument count
 * @argv: argument list
 *
 * Return: int
 */
int main(int argc, char *argv[])
{

	int exit_code = 0;
	
	if (argc != 2)
	{
		fprintf(stderr, "%s\n", "USAGE: monty file\n");
		return(EXIT_FAILURE);
	}
	if (argc == 2)
	{
		exit_code = read_file(argv[1]);
		free_stack();
		return (exit_code);
	}
	return (0);
}
