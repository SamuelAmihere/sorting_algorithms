#include "sort.h"

/**
 * find_max - Finds the maximum value in an array
 * @array: The array to search
 * @size: The size of the array
 * @max: The maximum value found
 * Return: Nothing
 */
void find_max(int *array, size_t size, int *max)
{
	size_t i;

	for (i = 0; i < size; i++)
		if (array[i] > *max)
			*max = array[i];
}

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * Counting sort algorithm
 *
 * @array: an array to sort
 * @size: array size
 *
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, max = 0;
	int i;

	if (!array || size < 2)
		return;

	find_max(array, size, &max);

	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;

	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}

	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
