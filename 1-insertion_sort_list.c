#include "sort.h"

/**
 * insertion_sort_list - implementation of insertion sort of doubly linked list
 * @list: idk yet
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp;
	int i = 0;

	if (!list)
		return;

	temp = *list;
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->n > temp->next->n)
		{
			i = temp->n;
			*(int *)&temp->n = temp->next->n;
			*(int *)&temp->next->n = i;
			temp = *list;
			print_list(*list);
		}
		else
			temp = temp->next;
	}
	