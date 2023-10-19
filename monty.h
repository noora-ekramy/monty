#ifndef MONTY_H
#define MONTY_H

#define PUSH 0
#define PALL 1
#define PINT 2
#define POP 3
#define SWAP 4
#define ADD 5
#define NOP 6
#define SUB 7
#define DIV 8
#define MUL 9
#define MOD 10
#define PCHAR 11
#define PSTR 12
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

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *stack;
extern instruction_t instructions[];

void interpret_file(char *filename);
char **parse_line(char *input);
int is_integer(char *str);
int opcode_to_const(char *opcode);
void run_command(char **arguments, int line_num);
void free_stack(void);

int push(char *str_value, int line_num);
int pop(unsigned int line_number);
int pint(int line_number);
int swap(int line_number);
int add(int line_number);
void pall(stack_t *stack);
int sub(int line_number);
int div_op(unsigned int line_number);
int mul(unsigned int line_number);
int mod(unsigned int line_number);
int pchar(int line_number);
int pstr();
#endif /* MONTY_H */
