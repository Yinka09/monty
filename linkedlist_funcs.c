#include "monty.h"

/**
 * linkedlist_len - returns the number of nodes in a doubly linked list
 * @head: pointer to the list
 *
 * Return: number of nodes
 */
size_t linkedlist_len(const linkedlist_t *head)
{
	size_t nodes = 0;

	if (!head)
		return (0);

	while (head)
	{
		nodes++;
		head = head->next;
	}

	return (nodes);
}

/**
 * get_index_node_int - gets the nth node of a doubly linked list
 * @head: pointer to the list
 * @index: index of the node to return
 *
 * Return: address of the node, or if it does not exist, NULL
 */
linkedlist_t *get_index_node_int(linkedlist_t *head, unsigned int index)
{
	unsigned int fig = 0;

	if (!head)
		return (NULL);

	while (head && fig < index)
	{
		head = head->next;
		fig++;
	}

	return (head ? head : NULL);
}

/**
 * add_node_int - adds a new node at the beginning of a doubly linked list
 * @head: double pointer to the list
 * @num: data to insert in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
linkedlist_t *add_node_int(linkedlist_t **head, const int num)
{
	linkedlist_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(linkedlist_t));
	if (!new)
		return (NULL);

	new->n = num;

	new->next = *head;
	new->prev = NULL;

	if (*head)
		(*head)->prev = new;

	*head = new;

	return (new);
}

/**
 * del_index_node_int - deletes a node in a doubly linked list
 * at a given index
 * @head: double pointer to the list
 * @index: index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int del_index_node_int(linkedlist_t **head, unsigned int index)
{
	linkedlist_t *temp = *head;
	unsigned int fig = 0;

	if (!index)
	{
		(*head) = temp->next;
		if (temp->next)
			temp->next->prev = NULL;
		temp->next = NULL;
		free(temp);
		return (1);
	}

	while (fig < index)
	{
		temp = temp->next;
		fig++;
		if (!temp)
			return (0);
	}

	temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	free(temp);

	return (1);
}

/**
 * print_list_int - prints a doubly linked list
 * @head: pointer to the list
 *
 * Return: number of nodes in the list
 */
size_t print_list_int(const linkedlist_t *head)
{
	size_t nodes = 0;

	if (!head)
		return (0);

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
		nodes++;
	}

	return (nodes);
}
