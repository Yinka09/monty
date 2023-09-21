#include "monty.h"
#include "linkedlists.h"

/**
 * free_all_data - custom memory handling function
 * @all_data: flag to indicate what to free
 */
void free_all_data(int all_data)
{
	if (data.line)
	{
		free(data.line);
		data.line = NULL;
		free_funcs(data.str);
		data.str = NULL;
	}

	if (all_data)
	{
		if (data.stack)
		{
			free_linkedlist_int(data.stack);
			data.stack = NULL;
		}
		if (data.fptr)
		{
			fclose(data.fptr);
			data.fptr = NULL;
		}
	}
}
