#include "lists.h"

/**
* check_cycle - Chekcks if LL has a cyle in it
*
* @list: listint pointer to linked list
*
* Return: 0 if there is no cycle, 1 if there is a cycle
*/

int check_cycle(listint_t *list)
{
	/* Initialize fast at the next node up from slow */
	listint_t *slow = list;
	listint_t *fast = list;

	while (slow && fast)
	{
		/* slow increments by one node, fast by 2 nodes */
		slow =  slow->next;
		fast = fast->next->next;

		/* If the collide than a cycle is found */
		if (slow == fast)
		{
			return (1);
		}
	}
	return (0);
	}
