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
	size_t len = 0, exit_stat = 0;
	int line_num = 1;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		exit_stat = execute(line, line_num);
		if (exit_stat == EXIT_FAILURE)
			break;
	}

	if (line != NULL)
		free(line);
	fclose(fp);
	return (exit_stat);
}
int execute(char *line, int line_num)
{
	int exit_stat = 0;
	char **arguments;

	arguments = parse_arguments(line);
	exit_stat = run_command(arguments, line_num);
	free(arguments);
	return (exit_stat);
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

	token = strtok(input, " \n");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, " \n");
	}
	tokens[i] = NULL;
	return (tokens);
}
