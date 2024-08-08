#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * quick_sort_recursive - Recursively sorts an array using Quick sort.
 * @array: The array to sort.
 * @low: The starting index of the sub-array.
 * @high: The ending index of the sub-array.
 * @size: The size of the array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = array[high];
		int i = low - 1;
		int j;

		for (j = low; j < high; j++)
		{
			if (array[j] <= pivot)
			{
				i++;
				if (i != j)
				{
					swap(&array[i], &array[j]);
					print_array(array, size);
				}
			}
		}
		if (array[high] < array[i + 1])
		{
			swap(&array[i + 1], &array[high]);
			print_array(array, size);
		}

		int pivot_index = i + 1;

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: Pointer to the array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
