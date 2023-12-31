#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in
 * ascending order
 *
 * @array: an array to sort
 * @size: the size of the array
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t min, i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		j = i + 1;

		while (j < size)
		{
			if (array[j] < array[min])
				min = j;
			j++;
		}

		if (min != i)
		{
			swap(&array[i], &array[min]);
			print_array(array, size);
		}
	}
}

/**
 * swap - swaps two integers in an array
 *
 * @x: current integer
 * @y: previous integer
 *
 * Return: Nothing
 */
void swap(int *x, int *y)
{
	int tmp;

	tmp = *y;
	*y = *x;
	*x = tmp;
}
