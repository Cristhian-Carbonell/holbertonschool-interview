#include "list.h"

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: list to modify
 * @str: string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *head = malloc(sizeof(List));
	List *tmp = *list;

	if (!head)
		return (NULL);
	head->str = strdup(str);
	if (!*list)
	{
		head->next = head;
		head->prev = head;
		*list = head;

		return (head);
	}

	head->next = *list;
	head->prev = (*list)->prev;
	(*list)->prev = head;
	head->prev->next = head;

	return (head);
}


/**
 * add_node_begin - Add a new node to the beginning
 * of a double circular linked list
 * @list: list to modify
 * @str: string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *head = add_node_end(list, str);

	if (!head)
		return (NULL);

	*list = head;

	return (head);
}
