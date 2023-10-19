#include "monty.h"

/**
 * parse_arguments - git the input
 *
 * Return: the input
 *
 * @input: command
 */

char **parse_arguments(char *input)
{
	char **tokens;
	char *token;
	int i, buffsize = 1024;

	if (input == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		return (NULL);
	}

	token = strtok(input, " \n");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, " \n");
	}
	tokens[i] = NULL;
	return (tokens);
}
