#include "sort.h"
/**
 * swap - Swap two nodes in a listint_t doubly-linked list.
 * @a: A pointer to the head of the doubly-linked list.
 * @b: A pointer to the first node to swap.
 */

void swap(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
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
	listint_t *node, *node2;

	if (!list || !*list || !(*list)->next)
		return;
	node = (*list)->next;
	while (node)
	{
	node2 = node;
	node = node->next;
	while (node2 && node2->prev)
	{
	if (node2->prev->next > node2->next)
	{
	swap(node2->prev, node2);
	if (!node2->prev)
	*list = node2;
	print_list((const listint_t *) *list);
	}
	else
	node2 = node2->prev;
	}
	}
}
