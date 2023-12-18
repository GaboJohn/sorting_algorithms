#include "sort.h"

/**
* merge - Merges two subarrays of the array in sorted order.
* @array: The array to be merged.
* @buffer: A buffer to store the merged result.
* @front: The front index of the array.
* @mid: The middle index of the array.
* @back: The back index of the array.
*/
void merge(int *array, int *buffer, size_t front, size_t mid, size_t back)
{
	size_t i = front, j = mid, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + front, mid - front);
	printf("[right]: ");
	print_array(array + mid, back - mid);

	while (i < mid && j < back)
		buffer[k++] = (array[i] < array[j]) ? array[i++] : array[j++];
	while (i < mid)
		buffer[k++] = array[i++];

	while (j < back)
		buffer[k++] = array[j++];

	for (i = front, k = 0; i < back; i++)
		array[i] = buffer[k++];
	printf("[Done]: ");
	print_array(array + front, back - front);
}

/**
* merge_sort_recursive - Recursively applies the merge sort algorithm.
* @array: The array to be sorted.
* @buffer: A buffer to store the merged result.
* @front: The front index of the array.
* @back: The back index of the array.
*/
void merge_sort_recursive(int *array, int *buffer, size_t front, size_t back)
{
	if (back - front > 1)
	{
	size_t mid = front + (back - front) / 2;

	merge_sort_recursive(array, buffer, front, mid);
	merge_sort_recursive(array, buffer, mid, back);
	merge(array, buffer, front, mid, back);
	}
}

/**
* merge_sort - Sorts an array of integers in ascending order using merge sort.
* @array: The array to be sorted.
* @size: The size of the array.
*/
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);
	free(buffer);
}
