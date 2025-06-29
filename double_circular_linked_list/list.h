#ifndef LIST_H
#define LIST_H

#include <stddef.h>

/**
 * struct List - doubly circular linked list
 * @str: string - (malloc'ed string)
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly circular linked list node structure
 * for project
 */
typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;

/* Function prototypes */
List *add_node_end(List **list, char *str);
List *add_node_begin(List **list, char *str);

#endif
