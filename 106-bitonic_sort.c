/*
 * File: 106-bitonic_sort.c
 * Auth: [Gabo John]
 */
#include "sort.h"

/**
 * swap_int - Swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bitonic_merge - Sorts a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @flow: The direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == 'U' && array[i] > array[i + jump]) ||
			    (flow == 'D' && array[i] < array[i + jump]))
			{
				swap_int(array + i, array + i + jump);
			}
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Converts an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == 'U') ? "UP" : "DOWN";

	if (seq > 1)
	{
			printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
			print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, 'U');
		bitonic_seq(array, size, start + cut, cut, 'D');
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);

		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using bitonic sort.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, 'U');
}
