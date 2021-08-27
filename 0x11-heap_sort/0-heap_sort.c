#include "sort.h"

/**
 * swap - swap two variables using a user defined
 * @xp: values pointed by xp
 * @yp:values pointed by yp
 */
void swap(int *xp, int *yp, int *array, size_t size)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
	print_array(array, size);
}

/**
 * sift_down - To heapify a subtree rooted with node i which is
 * an index in arr[]. n is size of heap
 * @array: array of values
 * @n: array size
 * @end: root element value
 * @size: size
 */
void sift_down(int *array, int n, int end, size_t size)
{
	int root = end;
	int left = 2 * end + 1;
	int right = 2 * end + 2;

	if (left < n && array[left] > array[root])
		root = left;
	if (right < n && array[right] > array[root])
		root = right;
	if (root != end)
	{
		swap(&array[end], &array[root], array, size);
		sift_down(array, n, root, size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending
 * @array: array of values
 * @size: array size
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i, size);
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i], array, size);
		sift_down(array, i, 0, size);
	}
}
