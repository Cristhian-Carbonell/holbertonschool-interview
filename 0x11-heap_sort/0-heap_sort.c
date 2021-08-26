#include "sort.h"

/**
 * swap - swap two variables using a user defined
 * @xp: values pointed by xp
 * @yp:values pointed by yp
 */
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 * sift_down - To heapify a subtree rooted with node i which is
 * an index in arr[]. n is size of heap
 * @array: array of values
 * @size: aray size
 * @end: root element value
 */
void sift_down(int *array, int size, int end)
{
	int root = end;
	int left = 2 * end + 1;
	int right = 2 * end + 2;
	int n = 0;

	if (left < size && array[left] > array[root])
		root = left;
	if (right < size && array[right] > array[root])
		root = right;
	if (root != end)
	{
		swap(&array[end], &array[root]);
		if (size < 10)
		{
			n = 10;
			print_array(array, n);
		}
		else
			print_array(array, size);
		sift_down(array, size, root);
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

	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i);
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, i, 0);
	}
}
