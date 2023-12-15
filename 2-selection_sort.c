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
 * selection_sort - Sort an array of integers in ascending order
 * using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	size_t sort, len;
	int *num;

	if (array == NULL || size < 2)
		return;

	for (sort = 0; sort < size - 1; sort++)
	{
		num = array + sort;

		for (len = sort + 1; len < size; len++)
		{
			if (array[len] < *num)
				num = array + len;
		}

		if ((array + sort) != num)
		{
			swap_int(array + sort, num);
			print_array(array, size);
		}
	}
}
