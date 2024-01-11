#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: double pointer to head of list
 * @node: node to swap with its previous node
 * Return: no return value (void)
*/
void swap_nodes(listint_t **list, listint_t *node)
{
	node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	node->next = node->prev;
	node->prev = node->prev->prev;
	node->next->prev = node;
	if (!node->prev)
		*list = node;
	else
		node->prev->next = node;
	print_list((const listint_t *)*list);
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: double pointer to head of list
 * Return: no return value (void)
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	for (current = (*list)->next; current; current = temp)
	{
		temp = current->next;
		while (current->prev && current->prev->n > current->n)
		{
			swap_nodes(list, current);
		}
	}
}
