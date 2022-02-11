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

	if (!head)
		return (NULL);
	head->str = _strdup(str);
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
