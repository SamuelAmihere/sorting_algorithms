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
    int swapped = 0;
    listint_t *current = *list;

    while (current->next != NULL)
    {
        if (current->n > current->next->n)
        {
            // Swap nodes
            if (current->prev != NULL)
                current->prev->next = current->next;
            else
                *list = current->next;

            current->next->prev = current->prev;
            current->prev = current->next;
            current->next = current->next->next;

            if (current->next != NULL)
                current->next->prev = current;

            current->prev->next = current;
            swapped = 1;

            print_list(*list);
        }
        else
        {
            current = current->next;
        }
    }

    return swapped;
}



/**
 * swap_backward - Move the smallest elements to the beginning in a backward pass
 *
 * @list: Pointer to a pointer to the head of the linked list
 *
 * Return: 1 if any elements are swapped, 0 if not
 */
int swap_backward(listint_t **list)
{
    int swapped = 0;
    listint_t *current = *list;

    // Move to the last node
    while (current->next != NULL)
        current = current->next;

    while (current->prev != NULL)
    {
        if (current->prev->n > current->n)
        {
            // Swap nodes
            current->prev->next = current->next;

            if (current->next != NULL)
                current->next->prev = current->prev;

            current->next = current->prev;
            current->prev = current->prev->prev;
            current->next->prev = current;

            if (current->prev != NULL)
                current->prev->next = current;

            swapped = 1;

            print_list(*list);
        }
        else
        {
            current = current->prev;
        }
    }

    return swapped;
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

    do
    {
        // Forward pass: Move the largest elements to the end
        swapped = swap_forward(list);

        // If no elements are swapped, the list is sorted
        if (!swapped)
            break;

        swapped = 0;

        // Decrease the end pointer as the largest element is now at the end
        swapped = swap_backward(list);

    } while (swapped);
}
