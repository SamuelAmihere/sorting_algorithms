#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: integer array to sort
 * @size: number of items in array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	int swaped = 1;
	size_t i, n;

	if (!size)
		return;
	n = size;
	while (swaped)
	{
		swaped = 0;

		for (i = 1; i < n; i++)
		{
			if (array && array[i] < array[i - 1])
			{
				swaped = 1;
				swap(&array[i], &array[i - 1]);
				print_array(array, size);
			}
		}
		n--;
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
