#include "monty.h"

/**
 * Pall - prints the stackS
 * @stack: stack given by main in start OF c
 * @line_cnt: amount of lines
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	print_stack(*stack);
}
