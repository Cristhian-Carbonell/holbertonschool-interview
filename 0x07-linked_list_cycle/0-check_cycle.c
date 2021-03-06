#include "lists.h"
#include <stdio.h>

/**
* check_cycle - checks if a singly linked list has a cycle in it
* @list: list to check
*
* Return: 0 if there is no cycle, 1 if there is a cycle
*/
int check_cycle(listint_t *list)
{
	listint_t *node = list->next;
	listint_t *current = list;

	if (!list)
		return (0);

	while (node)
	{
		if (node->next)
			node = node->next->next;
		else
			node = node->next;
		current = current->next;

		if (node == current)
			return (1);
	}

	return (0);
}

