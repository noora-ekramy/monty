#include "monty.h"

/**
 * interpret_file - Read and interpret Monty commands from a file.
 * @filename: The name of the Monty bytecode file to interpret.
 *
 * Return: Nothing.
 */
void interpret_file(char *filename)
{
	FILE *fp;
	char *line;
	char *argument, **arguments;
	size_t line_length = 1024, line_number;

	fp = fopen(filename, "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	for (line_number = 1; getline(&line, &line_length, fp) != EOF; line_number++)
	{
		arguments = parse_line(line);
		run_command(arguments, line_number);

		for (argument = *arguments; argument; argument++)
			free(argument);

		free(arguments);
	}

	if (line != NULL)
		free(line);

	fclose(fp);
}
