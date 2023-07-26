#include "sort.h"

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
 * shell_sort - Sorts the integers of an array in  ascending
 * order using the shell sorting algorithm
 * @array: An array of integers to be sorted
 * @size: The size of the array to be sorted
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, h, k;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (h = gap; h < size; h++)
		{
			k = h;
			while (k >= gap && array[k - gap] > array[k])
			{
				swap_ints(array + k, array + (k - gap));
				k -= gap;
			}
		}
		print_array(array, size);
	}

