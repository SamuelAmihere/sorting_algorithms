#include "sort.h"

/**
 * swap_forward - Move the largest elements to the end in a forward pass
 *
 * @list: Pointer to a pointer to the head of the linked list
 *
 * Return: 1 if any elements are swapped, 0 if not
 */
int swap_forward(listint_t **list)
{
	int swaped = 0;
	listint_t *curr = *list;

	while (curr)
	{
		if (curr->n <= curr->next->n)
			curr = curr->next;
		else
		{
			if (!curr->prev)
				*list = curr->next;
			else
				(curr->prev)->next = curr->next;

			curr->next->prev = curr->prev;
			curr->prev = curr->next;
			curr->next = (curr->next)->next;

			if (curr->next)
				(curr->next)->prev = curr;

			(curr->prev)->next = curr;
			swaped = 1;

			print_list(*list);
		}
	}
	return (swaped);
}

/**
 * swap_backward - Move the smallest elements to the beginning in a
 * backward pass
 *
 * @list: Pointer to a pointer to the head of the linked list
 *
 * Return: 1 if any elements are swapped, 0 if not
 */
int swap_backward(listint_t **list)
{
	int swapped = 0;
	listint_t *curr = *list;

	/* Move to the last node */
	while (curr)
		curr = curr->next;

	while (curr->prev)
	{
		if ((curr->prev)->n <= curr->n)
			curr = curr->prev;
		else
		{
			curr->prev->next = curr->next;

			if (curr->next)
				(curr->next)->prev = curr->prev;

			curr->next = curr->prev;
			curr->prev = (curr->prev)->prev;
			(curr->next)->prev = curr;

			if (curr->prev)
				(curr->prev)->next = curr;

			swapped = 1;

			print_list(*list);
		}
	}
	return (swapped);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using Cocktail Shaker Sort.
 *
 * @list: Pointer to a pointer to the head of the linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;

	if (!list || !(*list) || !(*list)->next)
		return;

	do {
		swapped = swap_forward(list);
		/* If no elements are swapped, the list is sorted */
		if (!swapped)
			break;

		swapped = 0;

		/*
		 * Decrease the end pointer as the largest element is now
		 at the end
		 */
		swapped = swap_backward(list);

	} while (swapped);
}
