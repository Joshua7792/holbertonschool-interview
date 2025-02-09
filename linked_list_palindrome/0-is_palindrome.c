#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse_list - Reverses a linked list.
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
    listint_t *slow = *head, *fast = *head, *second_half, *reversed_half;
    listint_t *first_half;

    if (*head == NULL || (*head)->next == NULL)
        return (1);

    /* Find the middle of the linked list */
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Reverse the second half */
    second_half = reverse_list(slow);
    reversed_half = second_half; /* Keep reference to restore list later */

    /* Compare the first half and the reversed second half */
    first_half = *head;
    while (reversed_half)
    {
        if (first_half->n != reversed_half->n)
        {
            reverse_list(second_half); /* Restore the original list */
            return (0);
        }
        first_half = first_half->next;
        reversed_half = reversed_half->next;
    }

    /* Restore the original list */
    reverse_list(second_half);
    return (1);
}
