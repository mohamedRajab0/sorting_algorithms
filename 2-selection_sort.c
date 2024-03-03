#include "sort.h"

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */


void selection_sort(int *array, size_t size)
{
	int i, j, minIndex, temp;

	for (i = 0; i < size - 1; i++)
	{
	minIndex = i;
	for (j = i + 1; j < size; j++)
	{
	if (array[j] < array[minIndex])
		minIndex = j;
	}
	temp = array[i];
	array[i] = array[minIndex];
	array[minIndex] = temp;
	print_array(array, size);
	}
}
