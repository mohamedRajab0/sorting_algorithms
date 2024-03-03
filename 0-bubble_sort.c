#include "sort.h"

/*
* bubble_sort
* @array: The array to be printed
* @size: Number of elements
*/

void bubble_sort(int *array, size_t size)
{
	size_t i = size, j = 0;
	int temp;

	if (array == NULL)
		return;

	for (i = size; i > 0; i--)
	{
		for (j = 0; j < (size - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
