#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @node: A pointer to the first node to swap.
 * @node2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **node, listint_t *node2)
{
	(*node)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node;
	node2->prev = (*node)->prev;
	node2->next = *node;
	if ((*node)->prev != NULL)
		(*node)->prev->next = node2;
	else
		*h = node2;
	(*node)->prev = node2;
	*node = node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = tmp)
	{
		tmp = i->next;
		j = i->prev;
		while (j != NULL && i->n < j->n)
		{
			swap_nodes(list, &j, i);
			print_list((const listint_t *)*list);
		}
	}
}
