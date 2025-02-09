#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse_list - Reverses a linked list in place.
 * @head: Pointer to the head of the list.
 * Return: Pointer to the new head of the reversed list.
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL, *next = NULL, *current = head;

    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: Double pointer to the head of the list.
 * Return: 1 if the list is a palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
    if (!head || !(*head) || !(*head)->next)
        return (1); /* Empty list or single node is always a palindrome */

    listint_t *slow = *head, *fast = *head, *first_half, *second_half, *reversed_half;

    /* Step 1: Find the middle of the list */
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Step 2: Reverse the second half of the list */
    second_half = reverse_list(slow);
    reversed_half = second_half; /* Store reference to restore later */

    /* Step 3: Compare the first and second halves */
    first_half = *head;
    while (reversed_half)
    {
        if (first_half->n != reversed_half->n)
        {
            reverse_list(second_half); /* Restore original list */
            return (0);
        }
        first_half = first_half->next;
        reversed_half = reversed_half->next;
    }

    /* Step 4: Restore the list before returning */
    reverse_list(second_half);
    return (1);
}
