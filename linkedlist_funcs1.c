#include "monty.h"
#include "linkedlists.h"

/**
 * free_linkedlist_int - frees a doubly linked list
 * @head: pointer to the list to free
 */
void free_linkedlist_int(linkedlist_t *head)
{
	linkedlist_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * add_node_int_end - adds a new node at the end of a doubly linked list
 * @head: double pointer to the list
 * @num: data to insert in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
linkedlist_t *add_node_int_end(linkedlist_t **head, const int num)
{
	linkedlist_t *new;
	linkedlist_t *temp = *head;

	if (!head)
		return (NULL);

	new = malloc(sizeof(linkedlist_t));
	if (!new)
		return (NULL);

	new->n = num;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new;
	new->prev = temp;

	return (new);
}

/**
 * insert_index_node_int - inserts a node at a given index
 * in a doubly linked list
 * @head: double pointer to the list
 * @index: index of the node to insert
 * @num: data to insert
 *
 * Return: address of the new node, or NULL if it failed
 */
linkedlist_t *insert_index_node_int(linkedlist_t **head,
		unsigned int index, int num)
{
	unsigned int fig;
	linkedlist_t *new;
	linkedlist_t *temp = *head;

	if (index == 0)
		return (add_node_int(head, num));

	for (fig = 0; temp && fig < index; fig++)
	{
		if (fig == index - 1)
		{
			if (temp->next == NULL)
				return (add_node_int(head, num));
			new = malloc(sizeof(linkedlist_t));
			if (!new || !head)
				return (NULL);
			new->n = num;
			new->next = NULL;
			new->next = temp->next;
			new->prev = temp;
			temp->next->prev = new;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}
