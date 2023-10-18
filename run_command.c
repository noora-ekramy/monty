#include "monty.h"
/** 
 *
 *
 *
 */
int run_command(char **arguments)
{
	int i = 0;

	while (arguments[i] != NULL)
	{
		printf(" arg %i :%s \n", i,arguments[i]);
		i++;
	}

	i = 0;
	/*
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(arguments[0], instructions[i].opcode) == 0)
		{
			instructions[i].f(&globalStack, );
			return (0);
		}
		i++;
	}
	*/
	if (strcmp(arguments[0], "push") == 0)
	{
            
	}
	fprintf(stderr, "Unknown instruction: %s\n", arguments[0]);
	return (0);
}
