#include "lists.h"

/**
 * is_palindrome - that checks if a singly linked list a palindrome
 * @head: the first node in the list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *root;
	listint_t *slow = *head;
	listint_t *fast = *head;
	/*listint_t *temp = *head;*/
	int node, count;

	if (!(*head))
		return (1);

	count = odd(&slow);
	while (slow != NULL)
	{
		if (fast != NULL && fast->next != NULL)
		{
			push(&root, slow->n);
			slow = slow->next;
			fast = fast->next->next;
		}
		else
		{
			if (count % 2 == 1)
			{
				slow = slow->next;
				node = pop(&root);
				if (slow->n != node)
					return (0);
				if (slow->next == NULL)
					return (1);
			}
			else
			{
				node = pop(&root);
				if (slow->n != node)
					return (0);
				slow = slow->next;
			}
		}
	}
	return (1);
}

/**
 * newNode - create a list for stack
 * @data: data to add to list
 *
 * Return: The pointer
 */
listint_t *newNode(int data)
{
	listint_t *stackNode = malloc(sizeof(listint_t));

	stackNode->n = data;
	stackNode->next = NULL;
	return (stackNode);
}

/**
 * push - push the data
 * @root: root from the stack
 * @data: data to store on the stack
 */
void push(listint_t **root, int data)
{
	listint_t *stackNode = newNode(data);

	stackNode->next = *root;
	*root = stackNode;
}

/**
 * pop - delete the last data entered
 * @root: root from the stack
 *
 * Return: return the deleted data
 */
int pop(listint_t **root)
{
	listint_t *temp = *root;
	int num;

	*root = (*root)->next;
	num = temp->n;
	free(temp);
	return (num);
}

/**
 * odd - a list is odd
 * @head: the first node in the list
 *
 * Return: list length
 */
int odd(listint_t **head)
{
	listint_t *temp = *head;
	int count = 0;

	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

