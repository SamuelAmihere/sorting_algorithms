#include "sort.h"

/**
 * partition_arr - Performs partitions on an array
 *
 * @array: an array to partition
 * @l: the lowest index of the array
 * @h: the highest index of the array
 * @size: array size
 *
 * Return: the index of the pivot
 */
int partition_arr(int *array, int l, int h, size_t size)
{
	int pivot = array[l];
	int i = l - 1, j = h + 1;

	while (i < j)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);
		if (array[i] != array[j])
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	return (j);
}

/**
 * sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 *
 * @array: an array to sort
 * @l: the lowest index of the array
 * @h: the highest index of the array
 * @size: array size
 *
 * Return: Nothing
 */
void sort(int *array, int l, int h, size_t size)
{
	int pivot;

	if (l < h)
	{
		pivot = partition_arr(array, l, h, size);

		sort(array, l, pivot, size);
		sort(array, pivot + 1, h, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick
 * sort algorithm
 *
 * @array: an array to sort
 * @size: array size
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	sort(array, 0, size - 1, size);
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
