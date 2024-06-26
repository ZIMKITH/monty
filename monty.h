#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <stdlib.h>

#define INSTRUCTIONS              \
{                           \
	{"push", push},       \
	{"pall", pall},   \
	{"pint", pint},   \
	{"pop", pop},     \
	{"swap", swap},   \
	{"nop", nop},     \
	{"div", _div},    \
	{"mul", _mul},    \
	{"add", _add},    \
	{"sub", _sub},    \
	{"mod", mod},     \
	{"pchar", pchar}, \
	{"pstr", pstr},   \
	{"rotl", rotl},   \
	{"rotr", rotr},   \
	{                     \
		NULL, NULL      \
	}                     \
}

/**
 * Struct stack_s - doubly linked list represents a stack and queue
 * @n: integer
 * @prev: points to the previous element of the stack.
 * @next: points to the next element of the stack.
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
 * Struct instruction_s - opcode and function
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

/**
 * Struct help - argument for the current opcode (queue)
 * @data_struct: stack mode, stack (default) and (queue)
 * @argument: the arguments of the string
 *
 * Description: global structure used to pass data around the functions easily
 */
typedef struct help
{
	int data_struct;
	char *argument;
} help;
help global;

/* stack utility functions available in linked_list.c */
size_t print_stack(const stack_t *stack);
stack_t *add_node(stack_t **stack, const int n);
stack_t *queue_node(stack_t **stack, const int n);
void free_stack(stack_t *stack);

void swap(stack_t **stack, unsigned int line_cnt);
void pop(stack_t **stack, unsigned int line_cnt);
void nop(stack_t **stack, unsigned int line_cnt);
void push(stack_t **stack, unsigned int line_cnt);
void pall(stack_t **stack, unsigned int line_cnt);
void pint(stack_t **stack, unsigned int line_cnt);

void _sub(stack_t **stack, unsigned int line_cnt);
void _mul(stack_t **stack, unsigned int line_cnt);
void mod(stack_t **stack, unsigned int line_cnt);
void _div(stack_t **stack, unsigned int line_cnt);
void _add(stack_t **stack, unsigned int line_cnt);

void rotl(stack_t **stack, unsigned int line_count);
void rotr(stack_t **stack, unsigned int line_count);
void pchar(stack_t **stack, unsigned int line_cnt);
void pstr(stack_t **stack, unsigned int line_cnt);

void opcode(stack_t **stack, char *str, unsigned int line_cnt);

int is_digit(char *string);
int isnumber(char *str);

#endif /* end of MONTY_H file */
