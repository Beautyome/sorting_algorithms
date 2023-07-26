#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sorts the integers of a subarray
 * @subarr: A subarray of an array of integers to sorted
 * @buff: A buffer to the store of the sorted subarray
 * @front: The index at the front of the array
 * @mid: The index at the middle of the array
 * @back: The index in the back of the array
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t m, n, o = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (m = front, n = mid; m < mid && n < back; o++)
		buff[o] = (subarr[m] < subarr[n]) ? subarr[m++] : subarr[n++];
	for (; m < mid; m++)
		buff[o++] = subarr[m];
	for (; n < back; n++)
		buff[o++] = subarr[n];
	for (m = front, o = 0; m < back; m++)
		subarr[m] = buff[o++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implements the merge sorting algorithm through a recursion
 * @subarr: A subarray of integers in an array to be sorted
 * @buff: A buffer to the store of the sorted results
 * @front: The front index of the subarray
 * @back: The back index of the subarray
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sorts the integers of an array in ascending
 * order using the merge sorting algorithm
 * @array: Array of integers
 * @size: Size of the array
 *
 * Description: Implements the top-down merge sorting algorithm
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);

