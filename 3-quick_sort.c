#include <stddef.h>
#include "sort.h"

/**
 * swap - swap 2 numbers
 * @array: array
 * @i: int 1
 * @j: int 2
 * @size: size
 */

void swap(int *array, int i, int j, int size)
{
	int temp = 0;

	if (array[i] != array[j])
	{
		temp = array[j];
		array[j] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
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

	quick_sort_rec(array, 0, size - 1, size);
}

/**
 * quick_sort_rec - a function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: the array of ints
 * @low: low
 * @high: high
 * @size: size
 */

void quick_sort_rec(int *array, int low, int high, int size)
{
	int pivot_index;

	if (low < high)
	{

		pivot_index = lomuto(array, low, high, size);
		quick_sort_rec(array, low, pivot_index - 1, size);
		quick_sort_rec(array, pivot_index + 1, high, size);
	}
}

/**
 * lomuto - partition function
 * @array: the array of ints
 * @low: low
 * @high: high
 * @size: size
 * Return: pivot
 */

int lomuto(int *array, int low, int high, int size)
{
	int pivot_value = array[high];
	int l, comp;

	l = low;
	for (comp = low; comp < high ; comp++)
	{
		if (array[comp] <= pivot_value)
		{
			swap(array, comp, l, size);
			l++;
		}
	}
	swap(array, comp, l, size);
	return (l);
}
