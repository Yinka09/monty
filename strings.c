#include "monty.h"
#include "linkedlists.h"

/**
 * free_funcs- frees arrays of strings
 * @args: array of strings to free
 */
void free_funcs(char **args)
{
	int fig;

	if (!args)
		return;

	for (fig = 0; args[fig]; fig++)
		free(args[fig]);

	free(args);
}

/**
 * **strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **grid, *tmp;
	int a, b = 0, c = 0, length = 0, strings, begin, end;

	length = strlen(str);
	strings = word_sum(str);
	if (strings == 0)
		return (NULL);

	grid = (char **) malloc(sizeof(char *) * (strings + 1));
	if (grid == NULL)
		return (NULL);

	for (a = 0; a <= length; a++)
	{
		if (isspace(str[a]) || str[a] == '\0' || str[a] == '\n')
		{
			if (c)
			{
				end = a;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (begin < end)
					*tmp++ = str[begin++];
				*tmp = '\0';
				grid[b] = tmp - c;
				b++;
				c = 0;
			}
		}
		else if (c++ == 0)
			begin = a;
	}

	grid[b] = NULL;

	return (grid);
}

/**
 * word_sum - helper function to count the number of words in a string
 * @str: string to evaluate
 *
 * Return: number of words
 */
int word_sum(char *str)
{
	int status, ch, count;

	status = 0;
	count = 0;

	for (ch = 0; str[ch] != '\0'; ch++)
	{
		if (str[ch] == ' ')
			status = 0;
		else if (status == 0)
		{
			status = 1;
			count++;
		}
	}

	return (count);
}
