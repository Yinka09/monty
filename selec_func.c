#include "monty.h"
#include "linkedlists.h"

/**
 * pall_func - handles the pall instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void pall_func(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack)
		print_list_int(*stack);
}

/**
 * push_func - handles the push instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void push_func(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	int number = 0, fig;

	if (data.str[1] == NULL)
	{
		fprintf(stderr, PUSH_FAILED, line_number);
		free_all_data(1);
		exit(EXIT_FAILURE);
	}

	for (fig = 0; data.str[1][fig]; fig++)
	{
		if (isalpha(data.str[1][fig]) != 0)
		{
			fprintf(stderr, PUSH_FAILED, line_number);
			free_all_data(1);
			exit(EXIT_FAILURE);
		}
	}
	number = atoi(data.str[1]);

	if (data.qflag == 0)
		new = add_node_int(stack, number);
	else if (data.qflag == 1)
		new = add_node_int_end(stack, number);
	if (!new)
	{
		fprintf(stderr, MALLOC_FAILED);
		free_all_data(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * selec_func - selects the right function
 * @token: line from the bytecode file passed to main
 *
 * Return: pointer to the selected function, or NULL on failure
 */
void (*selec_func(char **token))(stack_t **, unsigned int)
{
	instruction_t call_func_arr[] = {
		{"add", add_func},
		{"div", div_func},
		{"mod", mod_func},
		{"mul", mul_func},
		{"nop", nop_func},
		{"pall", pall_func},
		{"pchar", pchar_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{"pstr", pstr_func},
		{"push", push_func},
		{"queue", queue_func},
		{"rotl", rotl_func},
		{"rotr", rotr_func},
		{"stack", stack_func},
		{"sub", sub_func},
		{"swap", swap_func},
		{NULL, NULL}
	};

	int call = 17, fig;

	for (fig = 0; fig < call; fig++)
	{
		if (strcmp(call_func_arr[fig].opcode, token[0]) == 0)
		{
			return (call_func_arr[fig].f);
		}
	}
	return (NULL);
}
