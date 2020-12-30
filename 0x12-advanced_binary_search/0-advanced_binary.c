#include "search_algos.h"

/**
* advanced_binary - Searches for a value in a sorted array of integers
*
* @array: Pointer to the first element of the array
*
* @size: Number of elements in the array
*
* @value: Value to search for
*
* Return: Value searched for or -1 if aray is NULL
*/

int advanced_binary(int *array, size_t size, int value)
{
	if (array && size)
	{
		return (recursive_binary_search(array, 0, (int)size - 1, value));
	}
	/* Element not found */
	return (-1);
}

/**
* recursive_binary_search - Recursivly search array for element
*
* @array: Array of values
*
* @left: Left side search
*
* @value: Value to search for
*
* @right: Right side search
*
* Return: Value searched for or -1 on failure
*/

int recursive_binary_search(int *array, int left, int right, int value)
{
	int middle;
	{
		if (right >= left)
		{
			/* Find halway point of array */
			middle = left + (right - left) / 2;
			print_search(array, left, right);

			/* If value is found in middle */
			if (array[middle] == value)
			{
				return (middle);
			}

			/* If value is found to left of the middle, search left subarray */
			if (array[middle] > value)
			{
				return (recursive_binary_search(array, left, middle - 1, value));
			}
			/* Otherwise search for value in right subarray */
			return (recursive_binary_search(array, middle + 1, right, value));
		}
	}
	/* Element not found */
	return (-1);
}

/**
* print_search - Prints Search results
*
* @array: Array to search
*
* @first: First element
*
* @last: Last element
*
* Return: Void
*/

void print_search(int *array, int first, int last)
{
	int index = 0;

	printf("Searching in array: ");

	while (first <= last)
	{
		if (index > 0)
		{
			printf(", ");
		}
		index = first++;
		printf("%d", array[index++]);
	}
	printf("\n");
}
