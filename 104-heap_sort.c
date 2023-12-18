#include "sort.h"

/**
* swap - Swaps two elements in an array.
* @a: Pointer to the first element.
* @b: Pointer to the second element.
*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
* heapify - Creates a max heap from an array.
* @array: The array to be transformed into a heap.
* @size: The size of the array.
* @base: The base index for heapification.
* @root: The root node index for heapification.
*/
void heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, largest;
	left = 2 * root + 1;
	right = 2 * root + 2;
	largest = root;
	
	if (left < base && array[left] > array[largest])
		largest = left;
	if (right < base && array[right] > array[largest])
		largest = right;
	if (largest != root)
	{
		swap(&array[root], &array[largest]);
		print_array(array, size);
		heapify(array, size, base, largest);
	}
}

/**
* heap_sort - Sorts an array of integers in ascending order using heap sort.
* @array: The array to be sorted.
* @size: The size of the array.
*/
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;
	
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, size, i);
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
