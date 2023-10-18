#include "monty.h"

stack_t *globalStack = NULL;
instruction_t instructions[] = {
	{"push", push},
	{NULL, NULL}
};
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

	if (argc == 2)
	{
		exit_code = read_file(argv[1]);
		return (exit_code);
	}
	return (0);
}
