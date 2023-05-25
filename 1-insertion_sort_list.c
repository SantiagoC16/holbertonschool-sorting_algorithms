#include "sort.h"

/**
 * insertion_sort_list - implementation of insertion sort of doubly linked list
 * @list: idk yet
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted;

	if (*list == NULL || (*list)->next == NULL || list == NULL)
		return;
	sorted = NULL;
	current = *list;
	while (current != NULL)
	{
		listint_t *next = current->next;

		if (sorted == NULL || current->n < sorted->n)
		{
			current->next = sorted;
			if (sorted != NULL)
				sorted->prev = current;
			print_list(*list);
			sorted = current;
		}
		else
		{
			listint_t *temp = sorted;

			while (temp != NULL && temp->next != NULL &&
				current->n >= temp->next->n)
				temp = temp->next;

			current->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = current;
			print_list(*list);
			temp->next = current;
			current->prev = temp;
		}
		current = next;
	}
	*list = sorted;
}
