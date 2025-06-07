#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head of the list
 *
 * Return: address of the node where the loop starts, or NULL if no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	if (head == NULL || head->next == NULL)
		return (NULL);

	slow = head;
	fast = head;

	/* Phase 1: Detect if loop exists using Floyd's algorithm */
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;        /* Move slow pointer by 1 step */
		fast = fast->next->next;  /* Move fast pointer by 2 steps */

		if (slow == fast)         /* Loop detected */
			break;
	}

	/* If no loop found */
	if (fast == NULL || fast->next == NULL)
		return (NULL);

	/* Phase 2: Find the start of the loop */
	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return (slow);  /* Both pointers meet at the start of the loop */
}
