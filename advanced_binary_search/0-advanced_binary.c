#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - prints an array segment
 * @array: pointer to array
 * @low: start index
 * @high: end index
 */
void print_array(int *array, size_t low, size_t high)
{
	size_t i;

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
		printf("%d", array[i]);
		if (i < high)
			printf(", ");
	}
	printf("\n");
}

/**
 * binary_search_recursive - recursively searches for first occurrence
 * @array: pointer to array
 * @low: start index
 * @high: end index
 * @value: value to search for
 * Return: index of first occurrence or -1
 */
int binary_search_recursive(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	if (low > high)
		return (-1);

	print_array(array, low, high);
	mid = low + (high - low) / 2;

	if (array[mid] == value)
	{
		if (mid == low || array[mid - 1] != value)
			return ((int)mid);
		else
			return (binary_search_recursive(array, low, mid, value));
	}
	else if (array[mid] < value)
		return (binary_search_recursive(array, mid + 1, high, value));
	else
		return (binary_search_recursive(array, low, mid - 1, value));
}

/**
 * advanced_binary - wrapper to search for value in array
 * @array: pointer to array
 * @size: number of elements
 * @value: target value
 * Return: index or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_search_recursive(array, 0, size - 1, value));
}
