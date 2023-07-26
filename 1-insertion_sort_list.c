#include "sort.h"

/**
 * swap_nodes - Swaps the two nodes in a listint_t doubly linked list
 * @c: A pointer to the head of the doubly-linked list
 * @d1: A pointer to the first node to be swapped
 * @d2: The second node to be swapped
 */
void swap_nodes(listint_t **c, listint_t **d1, listint_t *d2)
{
	(*d1)->next = d2->next;
	if (d2->next != NULL)
		d2->next->prev = *d1;
	d2->prev = (*d1)->prev;
	d2->next = *d1;
	if ((*d1)->prev != NULL)
		(*d1)->prev->next = d2;
	else
		*c = d2;
	(*d1)->prev = d2;
	*d1 = d2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly-linked list of integers
 * using the insertion sorting algorithm
 * @list: A pointer to the head of a doubly-linked list of integers to be sorted
 *
 * Description: Prints the list after each swap is performed
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
