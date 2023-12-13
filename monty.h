#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>



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
 * struct instruction_s - opcode,functions and structures.
 * @opcode: the opcode
 * @f: The opcode functions
 *
 * Description: opcode, function and structures
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct global_variables
{
char *arg;
FILE *file;
char *line;

}glo_v;
extern glo_v gv;

extern void get_op_file(char *file);
extern void addnode(stack_t **top, int n);
void get_op_file(char *file);
int exec(char *line, stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);

/*ssize_t get_line(char **storage, size_t *size, FILE *stream);*/

/*Doubly linked list functions*/
void addnode(stack_t **top, int n);
int count_list(stack_t *top);



/*opcodes*/
void _push(stack_t **top, unsigned int line_number);
void _pall(stack_t **top, unsigned int line_number);
void _pint(stack_t **top, unsigned int line_number);
void _pop(stack_t **head, unsigned int line_number);
void _swap(stack_t **head, unsigned int line_number);
void _add(stack_t **top, unsigned int line_number);
void _nop(stack_t **top, unsigned int line_number);


#endif
