#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 * the shell sort algorithm
 *
 * @array: An array of integers to sort
 * @size: The size of the array
 *
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int temp;

	if (!array || size < 2)
		return;

	while (gap < size)
		gap = 1 + gap * 3;
	gap = (gap - 1) / 3;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = temp;
		}

		print_array(array, size);

		gap = (gap - 1) / 3;
	}
}
