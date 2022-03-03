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
 * max - returns maximun of two integers
 * @a: one integer
 * @b: two integer
 *
 * Return: returns maximun of two integers
 */
int max(int a, int b)
{
    return ((a >= b) ? a : b);
}

/**
 * height - compute the height of a tree.
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: if tree is not empty the height = 1 + max of left,
 * height and right heights
 */
int height(binary_tree_t *tree)
{
        if (!tree)
            return (0);

        return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * binary_tree_is_avl - function that checks if a binary tree is a valid AVL Tree
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise or
 * If tree is NULL, return 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int lh, rh;

    if(!tree)
        return (0);
    printf("%d\n", tree->n);

    lh = height(tree->left);
    rh = height(tree->right);
    printf("lh = %d, rh = %d\n", lh, rh)
;    if (abs(lh - rh) <= 1 && binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right))
    {
        printf("ingresa\n");
        if (isBSTUtil(tree, INT_MIN, INT_MAX))
            return (0);
        return (1);
    }

    return (0);
}

/**
 * binary_tree_node - creates a binary tree node
 * @parent: is a pointes to the parent node of the node to create
 * @value: is the value to put int the new node
 *
 * Return: a pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
        binary_tree_t *tempNode = NULL;

        tempNode = malloc(sizeof(binary_tree_t));

        if(!tempNode)
            return (0);

        tempNode->parent = parent;
        tempNode->n = value;
        tempNode->left = NULL;
        tempNode->right = NULL;

        return(tempNode);
}