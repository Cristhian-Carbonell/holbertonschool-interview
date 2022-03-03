#include "binary_trees.h"


/**
 * isBSTUtil - checking is it is a BTS
 * @node: is a pointer to node
 * @min: minimum number
 * @max: maximum number
 *
 * Return: true if the given tree is BST and
 * its values are >= min and <= max
 */
int isBSTUtil(const binary_tree_t *node, int min, int max)
{
    if (!node)
        return (0);

    if (node->n < min || node->n > max)
        return (0);

    return (isBSTUtil(node->left, min, node->n - 1) &&
            isBSTUtil(node->right, node->n + 1, max));
}

/**
 * isBSTUtil - checking is it is a BTS
 * @node: is a pointer to node
 * @min: minimum number
 * @max: maximum number
 *
 * Return: true if the given tree is BST
 */
int isBST(const binary_tree_t *node)
{
    return (isBSTUtil(node, INT_MIN, INT_MAX));
}
