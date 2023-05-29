#include "monty.h"

/**
 * rotl - puts top at the bottom
 * Return: 0 on success, -1 if fail
 */
int rotl(void)
{
	if (list_head == NULL || list_head->next == NULL)
		return (0);

	push_back(front());
	pop_front();
	return (0);
}

/**
 * rotr - put bottom at top
 * Return: 0 on success, -1 if fail
 */
int rotr(void)
{
	if (list_head == NULL || list_head->next == NULL)
		return (0);

	push_front(back());
	pop_back();
	return (0);
}
