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

	while (gap < size / 3)
		gap = 1 + gap * 3;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j > gap - 1 && array[j - gap] >= temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = temp;
		}

		gap = (gap - 1) / 3;
	}
}
