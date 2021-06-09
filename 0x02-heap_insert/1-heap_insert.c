#include "binary_trees.h"

/**
 *
 */
void swap(heap_t **arg_node, hea)
/**
 *
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *newNode;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	if (btree_is_perfect(*root) || !btree_is_perfect((*root)->left))
	{
		if ((*root)->left)
		{
			newNode = heap_insert(&((*root)->left), value);
			swap(root, &((*root)->left);
			return (newNode)
		}
	}
	return (NULL);
}
