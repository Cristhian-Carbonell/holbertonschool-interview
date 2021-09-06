#include "search_algos.h"

/**
 * advanced_binary - function that searches for a value in a
 * sorted array of integers.
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 *
 * Return: the index where value is located
 */
int advanced_binary(int *array, size_t size, int value)
{
	int index;

	if (array == NULL)
		return (-1);
	index = binarySearch(array, 0, size - 1, value);
	return (index);
}

/**
 * binarySearch - unction that searches for a value in a
 * sorted array of integers.
 * @array: is a pointer to the first element of the array to search in
 * @left: First element of array
 * @right: Last element of array
 * @value: is the value to search for
 *
 * Return: the index where value is located
 */
int binarySearch(int *array, int left, int right, int value)
{
	int mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;
		print_array(array, left, right);
		if (array[mid] >= value)
			return (binarySearch(array, left, mid, value));
		else
			return (binarySearch(array, mid + 1, right, value));
		return (mid);
	}
	if (array[left] == value)
		return (left);
	print_array(array, left, right);
	return (-1);

}

/**
 * print_array - the index where value is located
 * @array: is a pointer to the first element of the array to search in
 * @mid:  index where value is located
 * @size: is the number of elements in array
 */
void print_array(int *array, int mid, int size)
{
	printf("Searching in array: ");
	while (mid < size)
	{
		printf("%d, ", array[mid]);
		mid++;
	}
	printf("%d", array[mid]);
	printf("\n");
}