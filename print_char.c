#include "monty.h"
#include "linkedlists.h"

/**
 * pstr_func - handles the pstr instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void pstr_func(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	(void)line_number;

	if (!node)
	{
		putchar('\n');
		return;
	}

	while (node && node->n != 0 && node->n >= 0 && node->n <= 127)
	{
		putchar(node->n);
		node = node->next;
	}

	putchar('\n');
}

/**
 * pchar_func- handles the pchar instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void pchar_func(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (!node)
	{
		dprintf(STDERR_FILENO, PCHAR_FAILED, line_number);
		free_all_data(1);
		exit(EXIT_FAILURE);
	}

	if (node->n < 0 || node->n > 127)
	{
		dprintf(STDERR_FILENO, PCHAR_RANGE_ERR, line_number);
		free_all_data(1);
		exit(EXIT_FAILURE);
	}

	putchar(node->n);
	putchar('\n');
}
