#include "linkedlists.h"
#include "monty.h"

/**
 * queue_func - handles the queue instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void queue_func(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 1;
}

/**
 * stack_func - handles the stack instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void stack_func(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 0;
}

/**
 * rotr_func - handles the rotr instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void rotr_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int number = 0, length = linkedlist_len(*stack);

	(void)line_number;

	if (*stack == NULL)
		return;
	temp = get_index_node_int(*stack, length - 1);
	number = temp->n;
	del_index_node_int(stack, length - 1);
	add_node_int_end(stack, number);
}

/**
 * rotl_func - handles the rotl instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void rotl_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int number = 0;

	(void)line_number;

	if (*stack == NULL)
		return;
	temp = get_index_node_int(*stack, 0);
	number = temp->n;
	del_index_node_int(stack, 0);
	add_node_int_end(stack, number);
}
