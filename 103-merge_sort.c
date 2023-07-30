#include "sort.h"

/**
 * merge - Merges two sorted arrays into one sorted array
 *
 * @array: the original array containing both left and right arrays
 * @left: the left subarray to merge
 * @left_size: the size of the left subarray
 * @right: the right subarray to merge
 * @right_size: the size of the right subarray
 *
 * Return: Nothing
 */
static void merge(int *array, int *left, size_t left_size, int *right,
		size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *temp;

	temp = malloc(sizeof(int) * (left_size + right_size));
	if (!temp)
		return;

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			temp[k++] = left[i++];
		else
			temp[k++] = right[j++];
	}
	while (i < left_size)
		temp[k++] = left[i++];
	for (i = 0; i < left_size + right_size; i++)
		array[i] = temp[i];

	free(temp);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the merge sort algorithm
 *
 * @array: array to sort
 * @size: array size
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	size_t mid = size / 2;
	int *left, *right;

	if (!array || size < 2)
		return;

	left = array;
	right = array + mid;

	merge_sort(left, mid);
	merge_sort(right, size - mid);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, mid);
	printf("[right]: ");
	print_array(right, size - mid);

	merge(array, left, mid, right, size - mid);

	printf("[Done]: ");
	print_array(array, size);
}
