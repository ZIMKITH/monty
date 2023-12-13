#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * push - push interger in the stack
 * @stack: stack 0n main
 * @line_cnt: Created lines
 *
 * Return: Failure (0), succes = 1
 */
void push(stack_t **stack, unsigned int line_cnt)
{
        char *n = global.argument;

        if ((is_digit(n)) == 0)
        {
                fprintf(stderr, "L%d: usage: push integer\n", line_cnt);
                exit(EXIT_FAILURE);
        }

        if (global.data_struct == 1)
        {
                if (!add_node(stack, atoi(global.argument)))
                {
                        exit(EXIT_FAILURE);
                }
        }
        else
        {
                if (!queue_node(stack, atoi(global.argument)))
                {
                        exit(EXIT_FAILURE);
                }
        }
}
