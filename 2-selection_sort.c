#include "sort.h"

/**
 * swap_ints - Swaps an array two integers
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
 * selection_sort - Sort an array of integers in ascending order
 * using the selection sort algo
 * @array: Array of integers
 * @size: Size of the array
 *
 * Description: Prints the array after each of the swap
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t m, n;

	if (array == NULL || size < 2)
		return;

	for (m = 0; m < size - 1; m++)
	{
		min = array + m;
		for (n = m + 1; n < size; n++)
			min = (array[n] < *min) ? (array + n) : min;

		if ((array + m) != min)
		{
			swap_ints(array + m, min);
			print_array(array, size);
		}
	}
}
