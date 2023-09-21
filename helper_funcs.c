#include "monty.h"
#include "linkedlists.h"

/**
 * nop_func - handles the nop instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void nop_func(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * pint_func - handles the pint instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void pint_func(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!head)
	{
		fprintf(stderr, PINT_FAILED, line_number);
		free_all_data(1);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", head->n);
}

/**
 * pop_func - handles the pop instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void pop_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		fprintf(stderr, POP_FAILED, line_number);
		free_all_data(1);
		exit(EXIT_FAILURE);
	}

	del_index_node_int(stack, 0);
}

/**
 * swap_func - handles the swap instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void swap_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *node = NULL;
	int number;

	if (linkedlist_len(*stack) < 2)
	{
		fprintf(stderr, SWAP_FAILED, line_number);
		free_all_data(1);
		exit(EXIT_FAILURE);
	}

	temp = get_index_node_int(*stack, 0);
	number = temp->n;
	del_index_node_int(stack, 0);
	node = insert_index_node_int(stack, 1, number);
	if (!node)
	{
		fprintf(stderr, MALLOC_FAILED);
		free_all_data(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * add_func - handles the add instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void add_func(stack_t **stack, unsigned int line_number)
{
	int total = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_index_node_int(*stack, 0);
	stack_t *node_1 = get_index_node_int(*stack, 1);

	if (linkedlist_len(*stack) < 2)
	{
		fprintf(stderr, ADD_FAILED, line_number);
		free_all_data(1);
		exit(EXIT_FAILURE);
	}

	total = node_0->n + node_1->n;
	del_index_node_int(stack, 0);
	del_index_node_int(stack, 0);
	node = add_node_int(stack, total);
	if (!node)
	{
		fprintf(stderr, MALLOC_FAILED);
		free_all_data(1);
		exit(EXIT_FAILURE);
	}
}
