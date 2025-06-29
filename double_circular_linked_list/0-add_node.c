#include <stdlib.h>
#include "list.h"

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: Pointer to the list to modify
 * @str: String to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node, *last;
	int len, i;

	if (!list || !str)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	/* Calculate string length manually */
	len = 0;
	while (str[len])
		len++;

	new_node->str = malloc(len + 1);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	/* Copy string manually */
	for (i = 0; i <= len; i++)
		new_node->str[i] = str[i];

	if (*list == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}

	last = (*list)->prev;
	new_node->next = *list;
	new_node->prev = last;
	last->next = new_node;
	(*list)->prev = new_node;
	return (new_node);
}

/**
 * add_node_begin - Add a new node to the beginning of a double circular
 * linked list
 * @list: Pointer to the list to modify
 * @str: String to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node, *last;
	int len, i;

	if (!list || !str)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	/* Calculate string length manually */
	len = 0;
	while (str[len])
		len++;

	new_node->str = malloc(len + 1);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	/* Copy string manually */
	for (i = 0; i <= len; i++)
		new_node->str[i] = str[i];

	if (*list == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}
	last = (*list)->prev;
	new_node->next = *list;
	new_node->prev = last;
	(*list)->prev = new_node;
	last->next = new_node;
	*list = new_node;
	return (new_node);
}
