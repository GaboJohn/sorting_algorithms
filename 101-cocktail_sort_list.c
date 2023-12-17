#include "sort.h"

/**
 * swap_nodes_ahead - Swap a node in a listint_t doubly-linked list
 * with the node ahead of it.
 * @tail: A pointer to the tail of the doubly-linked list
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_nodes_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *curr = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = curr;
	else
		*list = curr;

	curr->prev = (*shaker)->prev;
	(*shaker)->next = curr->next;
	if (curr->next != NULL)
		curr->next->prev = *shaker;
	else
		*tail = *shaker;

	(*shaker)->prev = curr;
	curr->next = *shaker;
	*shaker = curr;
}

/**
 * swap_nodes_behind - Swap a node in a listint_t doubly-linked list
 * with the node behind it.
 * @tail: A pointer to the tail of the doubly-linked list
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_nodes_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *curr = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = curr;
	else
		*tail = curr;
	curr->next = (*shaker)->next;
	(*shaker)->prev = curr->prev;

	if (curr->prev != NULL)
		curr->prev->next = *shaker;
	else
		*list = *shaker;

	(*shaker)->next = curr;
	curr->prev = *shaker;
	*shaker = curr;
}
/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using Cocktail Shaker Sort.
 * @list: Pointer to the head of a doubly linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool swapped = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (swapped == false)
	{
		swapped = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_nodes_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				swapped = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list; shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_nodes_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				swapped = false;
			}
		}
	}
}
