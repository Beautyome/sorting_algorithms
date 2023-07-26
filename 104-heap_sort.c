#include "sort.h"

void swap_ints(int *c, int *d);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * max_heapify - Turns a binary tree into a complete binary heap
 * @array: An array of integers representing a binary tree
 * @size: The size of the array/tree
 * @base: The index of the base row of the binary tree
 * @root: The root node of the binary tree
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Sorts the integers of an array in ascending
 * order using the heap sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap is performed
 */
void heap_sort(int *array, size_t size)
{
	int j;

	if (array == NULL || size < 2)
		return;

	for (j = (size / 2) - 1; j >= 0; j--)
		max_heapify(array, size, size, j);

	for (j = size - 1; j > 0; j--)
	{
		swap_ints(array, array + j);
		print_array(array, size);
		max_heapify(array, size, j, 0);
	}
}
