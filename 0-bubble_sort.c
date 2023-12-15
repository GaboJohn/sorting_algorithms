#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * bubble_sort - Sorts an array of integers in ascending order using Bubble Sort
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len, sort;
	bool bubbly;

	for (i = 0; i < size - 1; i++)
	{
		for (len = 0; len < size - i - 1; len++)
		{
			if (array[len] > array[len + 1])
		{
			swap(&array[len], &array[len + 1]);

			for (sort = 0; sort < size; sort++)
			{

				printf("%d ", array[sort]);
			}
			printf("\n");

			bubbly = true;
		}
		}
		if (!bubbly)
			break;
	}
}
