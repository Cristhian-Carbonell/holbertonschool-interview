#include "lists.h"
#include <stdio.h>

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list:
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *node = list->next;

	if (list == NULL)
		return (0);

	while (node != NULL && node != list)
		node = node->next;
	if (node == NULL)
		return (0);

	return (1);
}

