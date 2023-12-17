#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int get_max, y;

	for (get_max = array[0], y = 1; y < size; y++)
	{
		if (array[y] > get_max)
			get_max = array[y];
	}

	return (get_max);
}
/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sort, max, i;

	if (array == NULL || size < 2)
		return;

	count = malloc(sizeof(int) * size);
	if (count == NULL)
		return;
	max = get_max(array, size);
	sort = malloc(sizeof(int) * (max + 1));
	if (sort == NULL)
	{
		free(count);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		sort[i] = 0;
	for (i = 0; i < (int)size; i++)
		sort[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		sort[i] += sort[i - 1];
	print_array(sort, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		count[sort[array[i]] - 1] = array[i];
		sort[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = count[i];

	free(count);
	free(sort);
}
