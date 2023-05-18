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
 * bubble_sort - a function that sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 * @array: the array of ints
 * @size: the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t count1 = 0, count2 = 0;

	for (count1 = size - 1; count1 != 0; count1--)
	{
		puts("caca  ");
		for (count2 = 1; count2 < count1; count2++)
			if (array[count2] > array[count2 + 1])
				swap(&array[count2], &array[count2 + 1]);
	}
}
