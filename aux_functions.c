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

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: Pointer to first node
 * @n: Elements of the list
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **stack, int n)
{
	struct stack_s *new_node = malloc(sizeof(stack_t));
	stack_t *tmp = *stack;

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*stack == NULL)
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new_node;
		new_node->prev = tmp;

	}
	return (new_node);
}
