#include "monty.h"

/**
 * parse_line - Tokenize an input line into an array of strings.
 * @input: The input line to be tokenized.
 *
 * Return: An array of strings containing the tokens from the input line.
 * The last element of the array is set to NULL. If there is an error, it
 * returns NULL.
 */
char **parse_line(char *input)
{
	char *token;
	char **tokens;
	int i, buffsize = 1024;

	if (input == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *) * buffsize);

	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
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
