#include <stddef.h>
#include "sort.h"

/**
 * swap - swap 2 numbers
 * @i: int 1
 * @j: int 2
 */

void swap(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * quick_sort - a function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: the array of ints
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
	{
		return;
	}

	quick_sort_rec(array, 0, size - 1);
}

/**
 * quick_sort_rec - a function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: the array of ints
 * @low: low
 * @high: high
 */

void quick_sort_rec(int *array, int low, int high)
{
	if (low == high)
	{
		return;
	}
	if (low < high)
	{
		int pivot_index;

		pivot_index = lomuto(array, low, high);
		quick_sort_rec(array, low, pivot_index - 1);
		print_array(array, high + 1);
		quick_sort_rec(array, pivot_index + 1, high);
		print_array(array, high + 1);
	}
}

/**
 * lomuto - partition function
 * @array: the array of ints
 * @low: low
 * @high: high
 * Return: pivot
 */

int lomuto(int *array, int low, int high)
{
	int pivot_value = array[high];
	int l, comp;

	l = low;
	for (comp = low; comp < high ; comp++)
	{
		if (array[comp] <= pivot_value)
		{
			swap(&array[l], &array[comp]);
			l++;
		}
	}
	swap(&array[l], &array[high]);
	return (l);
}
