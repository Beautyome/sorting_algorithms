#include "sort.h"

void swap_ints(int *c, int *d);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swaps an array of two integers
 * @c: The first integer to be swapped
 * @d: The second integer to be swapped
 */
void swap_ints(int *c, int *d)
{
	int tmp;

	tmp = *c;
	*c = *d;
	*d = tmp;
}

/**
 * lomuto_partition - Orders a subset of integers in an array according to
 * the lomuto partition scheme (last element as pivot)
 * @array: Array of the integers
 * @size: Size of the array
 * @left: The starting index of the subset to order
 * @right: The ending index of the subset to order
 *
 * Return: The final index partition
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implements the quicksort algor through recursion
 * @array: An array of integers to be sorted
 * @size: The size of the array to be sortef
 * @left: The starting index of the array partition to order
 * @right: The ending index of the array partition to order
 *
 * Description: Uses the Lomuto partition scheme
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort the integers in an array in ascending
 * order using the quicksort algorithm.
 * @array: Array of integers
 * @size: Size of the array
 *
 * Description: Uses the Lomuto partition scheme
 * Prints the array after each swap of the two elements
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
