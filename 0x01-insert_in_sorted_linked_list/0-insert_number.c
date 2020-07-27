#include "lists.h"

/**
 * insert_node - Inserts number in sorted linked list
 * @head: Head of linked list
 * @number: Value to add to sorted list
 *
 * Return: Sorted linked with value inserted
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current_node = *head;
	listint_t *prev = NULL;
	listint_t *new_node = malloc(sizeof(listint_t));

	if (!new_node)
	{
		return (NULL);
	}
	new_node->n = number;
	new_node->next = NULL;

	if (!*head)
	{
		*head = new_node;
	}
	else
	{
		while (current_node && current_node->n < number)
		{
			prev = current_node;
			current_node = current_node->next;
		}
		if (!prev)
		{
			new_node->next = *head;
			*head = new_node;
		}
		else if (current_node)
		{
			prev->next = new_node;
			new_node->next = current_node;
		}
		else
		{
			prev->next = new_node;
		}
	}
	return (new_node);
}
