#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - function that inserts a new node into a linked list sort
 * @head: a pointer pointing to the first node
 * @number: the new data to be stored in the linked list
 *
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newNode = NULL;
	listint_t *currentNode;

	newNode = malloc(sizeof(listint_t));

	if (!newNode)
		return (NULL);

	newNode->n = number;
	newNode->next = NULL;
	if (*head == NULL || (*head)->n >= newNode->n)
	{
		newNode->next = *head;
		*head = newNode;
	}
	else
	{
		currentNode = *head;
		while (currentNode->next != NULL && currentNode->next->n < newNode->n)
		{
			currentNode = currentNode->next;
		}

		newNode->next = currentNode->next;
		currentNode->next = newNode;
	}

	return (newNode);
}

