#include "sort.h"

void swap_ints(int *c, int *d);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swaps an array two integers
 * @c: The first integer to be swap
 * @d: The second integer to be swap
 */
void swap_ints(int *c, int *d)
{
	int tmp;

	tmp = *c;
	*c = *d;
	*d = tmp;
}

/**
 * hoare_partition - Orders a subset of integers in an array
 * according to the hoare partition scheme.
 * @array: Array of integers
 * @size: Size of the array
 * @left: The starting index of the subset to order
 * @right: The ending index of the subset to order
 *
 * Return: The final index partition
 *
 * Description: Uses the last element of the partition as the pivot
 * Prints the array after each swap of the two elements
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Implements the quicksort algo through recursion
 * @array: Array of integers to sorted
 * @size: Size of the array
 * @left: The starting index of array partition to order
 * @right: The ending index of array partition to order
 *
 * Description: Uses the Hoare partition scheme
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sorts integers of an array in ascending
 * order using the quicksort algor
 * @array: Array of integers
 * @size: Size of the array
 *
 * Description: Uses the Hoare partition scheme
 * Prints the array after each swap of the two elements
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
