#include "monty.h"
#include "linkedlists.h"

/**
 * sub_func - handles the sub instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void sub_func(stack_t **stack, unsigned int line_number)
{
	int subtract = 0;
	stack_t *node = NULL;
	stack_t *node0 = get_index_node_int(*stack, 0);
	stack_t *node1 = get_index_node_int(*stack, 1);

	if (linkedlist_len(*stack) < 2)
	{
		fprintf(stderr, SUB_FAILED, line_number);
		free_all_data(1);
		exit(EXIT_FAILURE);
	}

	subtract = node1->n - node0->n;
	del_index_node_int(stack, 0);
	del_index_node_int(stack, 0);
	node = add_node_int(stack, subtract);
	if (!node)
	{
		fprintf(stderr, MALLOC_FAILED);
		free_all_data(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * mul_func - handles the mul instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void mul_func(stack_t **stack, unsigned int line_number)
{
	int multiply = 0;
	stack_t *node = NULL;
	stack_t *node0 = get_index_node_int(*stack, 0);
	stack_t *node1 = get_index_node_int(*stack, 1);

	if (linkedlist_len(*stack) < 2)
	{
		fprintf(stderr, MUL_FAILED, line_number);
		free_all_data(1);
		exit(EXIT_FAILURE);
	}

	multiply = node1->n * node0->n;
	del_index_node_int(stack, 0);
	del_index_node_int(stack, 0);
	node = add_node_int(stack, multiply);
	if (!node)
	{
		fprintf(stderr, MALLOC_FAILED);
		free_all_data(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * div_func - handles the div instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void div_func(stack_t **stack, unsigned int line_number)
{
	int division = 0;
	stack_t *node = NULL;
	stack_t *node0 = get_index_node_int(*stack, 0);
	stack_t *node1 = get_index_node_int(*stack, 1);

	if (linkedlist_len(*stack) < 2)
	{
		fprintf(stderr, DIV_FAILED, line_number);
		free_all_data(1);
		exit(EXIT_FAILURE);
	}

	if (node0->n == 0)
	{
		fprintf(stderr, DIV_ZERO_ERR, line_number);
		free_all_data(1);
		exit(EXIT_FAILURE);
	}

	division = node1->n / node0->n;
	del_index_node_int(stack, 0);
	del_index_node_int(stack, 0);
	node = add_node_int(stack, division);
	if (!node)
	{
		fprintf(stderr, MALLOC_FAILED);
		free_all_data(1);
		exit(EXIT_FAILURE);
	}
}



/**
 * mod_func - handles the mod instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void mod_func(stack_t **stack, unsigned int line_number)
{
	int modulus = 0;
	stack_t *node = NULL;
	stack_t *node0 = get_index_node_int(*stack, 0);
	stack_t *node1 = get_index_node_int(*stack, 1);

	if (linkedlist_len(*stack) < 2)
	{
		fprintf(stderr, MOD_FAILED, line_number);
		free_all_data(1);
		exit(EXIT_FAILURE);
	}

	if (node0->n == 0)
	{
		fprintf(stderr, DIV_ZERO_ERR, line_number);
		free_all_data(1);
		exit(EXIT_FAILURE);
	}

	modulus = node1->n % node0->n;
	del_index_node_int(stack, 0);
	del_index_node_int(stack, 0);
	node = add_node_int(stack, modulus);
	if (!node)
	{
		fprintf(stderr, MALLOC_FAILED);
		free_all_data(1);
		exit(EXIT_FAILURE);
	}
}
