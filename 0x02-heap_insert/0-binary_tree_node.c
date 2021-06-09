#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: is a pointer to the parent node of node to create
 * @value: is the value to put in the new node
 *
 * Return: a pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode = malloc(sizeof(binary_tree_t));

	if (!newNode)
		return (NULL);
	newNode->parent = parent;
	newNode->n = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return (newNode);
}

