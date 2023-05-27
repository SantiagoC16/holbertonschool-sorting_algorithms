#include "sort.h"

/**
 * insertion_sort_list - implementation of insertion sort of doubly linked list
 * @list: idk yet
 */

void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current , *temp, *pretemp;
	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		pretemp = current->prev;

		while (pretemp != NULL && pretemp->n > temp->n)
		{
			pretemp->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = pretemp;

			temp->prev = pretemp->prev;
			temp->next = pretemp;

			if (pretemp->prev != NULL)
				pretemp->prev->next = temp;
			else
				*list = temp;

			pretemp->prev = temp;
			pretemp = temp->prev;

			print_list(*list);
		}
		current = current->next;
	}
}
