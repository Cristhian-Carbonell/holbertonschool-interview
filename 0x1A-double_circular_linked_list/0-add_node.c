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
	if (!*list)
	{
		*list = createNode(&(*list), str);
		return (*list);
	}
	head->str = str;
	head->next = *list;
	if ((*list)->next == NULL && (*list)->prev == NULL)
	{
		(*list)->next = head;
		(*list)->prev = head;
		head->prev = *list;
	} else
	{
		(*list)->prev = head;
		tmp = (*list)->next;
		if (tmp->next == NULL && tmp->prev == NULL)
		{
			tmp->prev = *list;
			tmp->next = head;
			head->prev = tmp;
		} else
		{
			while (tmp->next != *list)
				tmp = tmp->next;
			tmp->prev = tmp->prev;
			tmp->next = head;
			head->prev = tmp;
		}
	}

	return (*list);
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
	List *head = malloc(sizeof(List));
	List *tmp = *list;

	if (!head)
		return (NULL);
	if (!*list)
	{
		*list = createNode(&(*list), str);
		return (*list);
	}
	head->str = str;
	head->next = *list;
	if (tmp->next == NULL && tmp->prev == NULL)
	{
		tmp->next = head;
		tmp->prev = head;
		head->prev = tmp;
		*list = head;
	} else
	{
		tmp->prev = head;
		while (tmp->next != *list)
			tmp = tmp->next;
		tmp->next = head;
		tmp->prev = tmp->prev;
		head->prev = tmp;
		*list = head;
	}

	return (*list);
}

/**
 * createNode - create a new node
 * @list: list to modify
 * @str: string to copy into the new node
 *
 * Return: Address of the new node
 */
List *createNode(List **list, char *str)
{
	List *head = malloc(sizeof(List));

	if (!head)
		return (NULL);

	head->str = str;
	head->next = NULL;
	head->prev = NULL;
	*list = head;

	return (*list);
}

