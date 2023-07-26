#include "sort.h"

void swap_ints(int *c, int *d);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

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
 * bitonic_merge - Sorts a bitonic seq inside integers of an array
 * @array: Array of integers
 * @size: Size of the array
 * @start: The starting index of the seq in array to be sorted
 * @seq: The size of the seq to be sorted
 * @flow: The dir to sorted in
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t j, jump = seq / 2;

	if (seq > 1)
	{
		for (j = start; j < start + jump; j++)
		{
			if ((flow == UP && array[j] > array[j + jump]) ||
			    (flow == DOWN && array[j] < array[j + jump]))
				swap_ints(array + j, array + j + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Converts the integers of an array into a biton seq
 * @array: An array of integers
 * @size: The size of the array
 * @start: The starting index of a block of the building bitonic seq
 * @seq: The size of a block of the building bitonic seq
 * @flow: The dir to sort the bitonic seq block in
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sorts the integers of an array in ascending
 * order using the bitonic sort algorithm.
 * @array: Array of integers
 * @size: Size of the array
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);

