#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data_s - extern data to access inside functions
 * @line: line from the file
 * @str: parsed line
 * @stack: pointer to the stack
 * @fptr: file pointer
 * @qflag: flag for queue or stack
 */
typedef struct data_s
{
	char *line;
	char **str;
	stack_t *stack;
	FILE *fptr;
	int qflag;
} data_t;

/**
 * struct arg_s - structure of arguments from main
 * @av: name of the file from the command line
 * @ac: number of arguments from main
 * @line_number: number of the current line in the file
 *
 * Description: arguments passed to main from the command line
 * used in different functions, organized in a struct for clarity
 */
typedef struct arg_s
{
	char *av;
	int ac;
	unsigned int line_number;
} arg_t;

typedef stack_t linkedlist_t;

extern data_t data;

#define DATA_INIT {NULL, NULL, NULL, NULL, 0}

#define USAGE_ERR "USAGE: monty file\n"
#define FILE_ERR "Error: Can't open file %s\n"
#define UNKNOWN_ERR "L%u: unknown instruction %s\n"
#define MALLOC_FAILED "Error: malloc failed\n"
#define PUSH_FAILED "L%u: usage: push integer\n"
#define PINT_FAILED "L%u: can't pint, stack empty\n"
#define POP_FAILED "L%u: can't pop an empty stack\n"
#define SWAP_FAILED "L%u: can't swap, stack too short\n"
#define ADD_FAILED "L%u: can't add, stack too short\n"
#define SUB_FAILED "L%u: can't sub, stack too short\n"
#define DIV_FAILED "L%u: can't div, stack too short\n"
#define DIV_ZERO_ERR "L%u: division by zero\n"
#define MUL_FAILED "L%u: can't mul, stack too short\n"
#define MOD_FAILED "L%u: can't mod, stack too short\n"
#define PCHAR_FAILED "L%u: can't pchar, stack empty\n"
#define PCHAR_RANGE_ERR "L%u: can't pchar, value out of range\n"

/* free_data.c */
void free_all_data(int all_data);

/* helper_funcs.c */
void add_func(stack_t **stack, unsigned int line_number);
void nop_func(stack_t **stack, unsigned int line_number);
void pint_func(stack_t **stack, unsigned int line_number);
void pop_func(stack_t **stack, unsigned int line_number);
void swap_func(stack_t **stack, unsigned int line_number);

/* helper_funcs1.c */
void div_func(stack_t **stack, unsigned int line_number);
void mul_func(stack_t **stack, unsigned int line_number);
void mod_func(stack_t **stack, unsigned int line_number);
void sub_func(stack_t **stack, unsigned int line_number);

/* helper_funcs2.c */
void queue_func(stack_t **stack, unsigned int line_number);
void rotl_func(stack_t **stack, unsigned int line_number);
void rotr_func(stack_t **stack, unsigned int line_number);
void stack_func(stack_t **stack, unsigned int line_number);


/* main.c */
void monty_func(arg_t *args);

/* print_char.c */
void pchar_func(stack_t **stack, unsigned int line_number);
void pstr_func(stack_t **stack, unsigned int line_number);

/* selec_func.c */
void push_func(stack_t **stack, unsigned int line_number);
void (*selec_func(char **token))(stack_t **, unsigned int);
void pall_func(stack_t **stack, unsigned int line_number);

/* string.c */
char **strtow(char *str);
int word_sum(char *str);
void free_funcs(char **args);

#endif
