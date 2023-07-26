#include "sort.h"

/**
 * swap_ints - Swaps an array of two integers
 * @c: The first integer to be swapped in an array
 * @d: The second integer to be swapped in an array
 */
void swap_ints(int *c, int *d)
{
	int tmp;

	tmp = *c;
	*c = *d;
	*d = tmp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * @array: An array of integers to be sorted
 * @size: The size of the array to be sorted
 *
 * Description: Prints an array of integers after each swap
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (j = 0; j < len - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_ints(array + j, array + j + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}

