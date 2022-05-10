#include "monty.h"
/**
 * free_dlistint - Function that free a list
 * @head: Pointer to first node
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * is_digit - Check if the characters are positive numbers
 * @str: Number to check
 * Return: 0 if succes or -1 if not succes
 */
int is_digit(char *str)
{
	int i = 0;

	if (str[0] == '-')
		i = 1;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}
