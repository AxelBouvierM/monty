#include "monty.h"
/**
 * _push - pushes an element to the stack
 * @stack: First element (head)
 * @line_number: is the line number where the instruction appears
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	char *str = NULL;
	int num = 0;

	tmp = malloc(sizeof(stack_t));
	if (tmp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		if (*stack != NULL)
		{
			free_dlistint(*stack);
		}
		exit(EXIT_FAILURE);
	}
	str = strtok(NULL, "\t\n ");
	if (str == NULL || is_digit(str) == -1)
	{
		fprintf(stderr, "L<%d>: unknown instruction <push>", line_number);
		free(tmp);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	num = atoi(str);
	tmp->n = num;
	tmp->prev = NULL;
	if (*stack == NULL)
	{
		tmp->next = NULL;
		*stack = tmp;
	}
	else
	{
		tmp->next = *stack;
		(*stack)->prev = tmp;
		*stack = tmp;
	}
}

/**
 * _pall - prints all the values, starting from the top of the stack
 * @stack: First element (head)
 * @line_number: is the line number where the instruction appears
 */
void _pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
		return;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * _pint - prints the value at the top of the stack, followed by a new line
 * @stack: First element (head)
 * @line_number: is the line number where the instruction appears
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}

/**
 * _pop - removes the top element of the stack
 * @stack: First element (head)
 * @line_number: is the line number where the instruction appears
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
}
