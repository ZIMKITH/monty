#include "monty.h"
glo_v gv = {NULL, NULL, NULL};

/**
 * main - main file
 * @argc: arguments count
 * @argv: monty file pin
 * Return: 1 on success, on error = 0
 */

int main(int argc, char *argv[])
{
    stack_t *stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    get_op_file(argv[1]);

    addnode(&stack, 10);
    addnode(&stack, 20);
    addnode(&stack, 30);

    free_stack(stack);

    return 0;
}
