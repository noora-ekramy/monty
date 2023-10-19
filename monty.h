#ifndef MONTY_H
#define MONTY_H

#define STACK 0
#define QUEUE 1
#define Basic_Fun 2

#define SWAP 4
#define ADD 5
#define NOP 6
#define SUB 7
#define DIV 8
#define MUL 9
#define MOD 10
#define PCHAR 11
#define PSTR 12
#define ROTL 13
#define ROTR 14
#define INVALID_OPCODE -1

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

extern stack_t *memStackHead;
extern stack_t *memStackTail;
extern int dataStructuer;

int read_file(char *filename);
int execute(char *line, int line_num);
char **parse_arguments(char *input);
int is_integer(char *str);
int get_opcode(char *opcode);
int run_command(char **arguments, int line_num);


/*basic mem functions*/
int runbasic_op(char * function, int lineNum, char **arguments);
void pall();
void free_mem();
int push(char *str_value, int line_num);
int pop(unsigned int line_number);
int pint(int line_number);

int swap(int line_number);
int add(int line_number);
int sub(int line_number);
int div_op(unsigned int line_number);
int mul_op(unsigned int line_number);
int mod_op(unsigned int line_number);
int pchar_op(int line_number);
int pstr_op();
int rotl_op();
int rotr_op();
#endif /* MONTY_H */
