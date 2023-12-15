#include "sort.h"

/**
 * swap_int - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap_int(int *a, int *b)
{
	 int temp = *a;
	 *a = *b;
	 *b = temp;
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme
 * @array: Array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: Index of the pivot after partitioning
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int pvt = array[high];
	size_t m = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pvt)
		{
			m++;
			if (m != j)
			{
				swap_int(&array[m], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (m + 1 != high)
	{
		swap_int(&array[m + 1], &array[high]);
		print_array(array, size);
	}
	return (m + 1);
}

/**
 * quick_sort_recursive - Recursively sorts the array using Quick Sort
 * @array: Array to be sorted
 * @low: Starting index of the array
 * @high: Ending index of the array
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
	if (low < high)
	{
		size_t pvt = lomuto_partition(array, low, high, size);

		if (pvt != 0)
			quick_sort_recursive(array, low, pvt - 1, size);
		quick_sort_recursive(array, pvt + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick Sort algorithm with Lomuto partition scheme.
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}
