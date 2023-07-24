#include "sort.h"

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
