#include <stddef.h>
#include "sort.h"

/**
 * quick_sort - a function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: the array of ints
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	size_t count1 = 0, count2 = 0;

	if (array == NULL || size <= 1)
	{
		return;
	}
	for (count1 = size - 1; count1 != 0; count1--)
	{
		for (count2 = 0; count2 < count1; count2++)
		{
			if (array[count2] > array[count2 + 1])
			{
				swap(&array[count2], &array[count2 + 1]);
				print_array(array, size);
			}
		}
	}
}
