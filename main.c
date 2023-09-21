#include "monty.h"
#include "linkedlists.h"

data_t data = DATA_INIT;

/**
 * monty_func - helper function for main function
 * @args: pointer to struct of arguments from main
 *
 * Description: opens and reads from the file
 * containing the opcodes, and calls the function
 * that will find the corresponding executing function
 */
void monty_func(arg_t *args)
{
	size_t length = 0;
	int read = 0;
	void (*func_for_code)(stack_t **, unsigned int);

	if (args->ac != 2)
	{
		fprintf(stderr, USAGE_ERR);
		exit(EXIT_FAILURE);
	}
	data.fptr = fopen(args->av, "r");
	if (!data.fptr)
	{
		fprintf(stderr, FILE_ERR, args->av);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		args->line_number++;
		read = _getline(&(data.line), &length, data.fptr);
		if (read < 0)
			break;
		data.str = strtow(data.line);
		if (data.str[0] == NULL || data.str[0][0] == '#')
		{
			free_all_data(0);
			continue;
		}
		func_for_code = selec_func(data.str);
		if (!func_for_code)
		{
			fprintf(stderr, UNKNOWN_ERR, args->line_number, data.str[0]);
			free_all_data(1);
			exit(EXIT_FAILURE);
		}
		func_for_code(&(data.stack), args->line_number);
		free_all_data(0);
	}
	free_all_data(1);
}

/**
 * main - entry point for monty bytecode interpreter
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	arg_t args;

	args.av = argv[1];
	args.ac = argc;
	args.line_number = 0;

	monty_func(&args);

	return (EXIT_SUCCESS);
}
