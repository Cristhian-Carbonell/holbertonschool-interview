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
		tmp = createNode(list, str);
		return (tmp);
	}
	head->str = _strdup(str);
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
	List *head = malloc(sizeof(List));
	List *tmp = *list;

	if (!head)
		return (NULL);
	if (!*list)
	{
		tmp = createNode(list, str);
		return (tmp);
	}
	head->str = _strdup(str);
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

	return (head);
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

	head->str = _strdup(str);
	head->next = head;
	head->prev = head;
	*list = head;

	return (head);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: character
 *
 * Return: a pointer to a new string which is a duplicate of the string
 */
char *_strdup(char *str)
{
	int i, j;
	char *ptr;

	if (str == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		;
	}
	ptr = malloc((i + 1) * sizeof(char));

	if (ptr == NULL)
	{
		return (NULL);
	}
	for (j = 0; j <= i; j++)
	{
		ptr[j] = str[j];
	}
	ptr[j] = '\0';
	return (ptr);
}
