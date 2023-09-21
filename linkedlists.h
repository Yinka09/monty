#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

#include "monty.h"

/* linkedlist_funcs.c */
linkedlist_t *get_index_node_int(linkedlist_t *head, unsigned int index);
size_t print_list_int(const linkedlist_t *head);
int del_index_node_int(linkedlist_t **head, unsigned int index);
size_t linkedlist_len(const linkedlist_t *head);
linkedlist_t *add_node_int(linkedlist_t **head, const int num);

/* linkedlist_funcs1.c */
void free_linkedlist_int(linkedlist_t *head);
linkedlist_t *add_node_int_end(linkedlist_t **head, const int num);
linkedlist_t *insert_index_node_int(linkedlist_t **head,
		unsigned int index, int num);

#endif
