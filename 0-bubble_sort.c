#include "sort.h"
/**
 * swap - Échange deux éléments d'un tableau
 * @a: premier élément
 * @b: deuxième élément
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - sort with the bubble technique
 * @array: tableau
 * @size: taille
 *
 * Return: array sort by the bubble technique
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
