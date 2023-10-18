#include "monty.h"
/**
 * read_file - Read Command From File
 * @filename: File name
 * Return: -1 or  0
 */
int read_file(char *filename)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0, exit_code = 0;
	char **arguments;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "./monty: 0: Can't open %s\n", filename);
		return (127);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		arguments = parse_arguments(line);
		exit_code = run_command(arguments);
		free(arguments);

	}
	if (line != NULL)
		free(line);
	fclose(fp);

	return (exit_code);
}
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

	token = strtok(input, " ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;
	return (tokens);
}
