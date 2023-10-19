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
	int line_num = 1;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return(EXIT_FAILURE);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		
		arguments = parse_line(line);
		exit_code = run_command(arguments, line_num);
		free(arguments);
		if (exit_code == EXIT_FAILURE)
		{
			break;
		}
		else if (exit_code == EXIT_FAILURE + 1)
			exit_code = EXIT_FAILURE;
		line_num++;
	}
	if (line != NULL)
		free(line);
	fclose(fp);

	return (exit_code);
}
