#include "monty.h"
/**
 * is_comment - Checks if a string represents a comment.
 * @line: The input string.
 *
 * Return: 1 if the line is a comment, 0 otherwise.
 */
int is_comment(char *line)
{

    if (*line == '#')
    {
        return 1;
    }
    return 0;
}