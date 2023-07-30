#include "sort.h"

/**
* create_listint - Creates a doubly linked list from an array of integers
*
* @array: Array to convert to a doubly linked list
* @size: Size of the array
*
* Return: Pointer to the first element of the created list. NULL on failure
*/
listint_t *create_listint(const int *array, size_t size)
{
listint_t *list;
listint_t *node;
int *tmp;

list = NULL;
while (size--)
{
node = malloc(sizeof(*node));
if (!node)
return (NULL);
tmp = (int *)&node->n;
*tmp = array[size];
node->next = list;
node->prev = NULL;
list = node;
if (list->next)
list->next->prev = list;
}
return (list);
}

/**
* headp_sort - Sorts an array of integers in ascending order
* using the heap sort algorithm
* 
* @array: array to sort
* @size: array size
* 
* Return: Nothing
*/
void heap_sort(int *array, size_t size)
{
size_t i;
int temp;

if (!array || size < 2)
return;

for (i = size / 2 - 1; (int)i >= 0; i--)
heapify(array, size, i, size);

for (i = size - 1; i > 0; i--)
{
temp = array[0];
array[0] = array[i];
array[i] = temp;
print_array(array, size);
heapify(array, i, 0, size);
}
}
