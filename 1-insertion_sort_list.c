#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the insertion sort
 * algorithm
 *
 * @list: a doubly linked list to sort
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *next, *prev;
	int n;

	if (!list || !*list || ((*list)->next == NULL
				&& (*list)->prev == NULL))
		return;

	curr = *list;
	while (curr)
	{
		n = curr->n;
		next = curr->next;
		prev = curr->prev;

		while (prev && prev->n > n)
		{
			if (prev->prev)
				(prev->prev)->next = curr;
			else
				*list = curr;

			prev->next = curr->next;
			if (curr->next)
				(curr->next)->prev = prev;

			curr->prev = prev->prev;
			curr->next = prev;
			prev->prev = curr;

			print_list(*list);

			prev = curr->prev;
		}

		curr = next;
	}
}
