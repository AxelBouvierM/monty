#include "monty.h"
/**
 * _mod - computes the rest of the division of the second top element
 * @stack: First element (head)
 * @line_number: is the line number where the instruction appears
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int mod;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	mod = (*stack)->next->n % (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = mod;
}

/**
 * _pchar - prints the char at the top of the stack, followed by a new line
 * @stack: First element (head)
 * @line_number: is the line number where the instruction appears
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (isascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * _pstr -  prints the string starting at the top of the stack
 * @stack: First element (head)
 * @line_number: is the line number where the instruction appears
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}
	while (tmp != NULL)
	{
		if (tmp->n == 0)
			break;
		if (isascii(tmp->n) == 0)
			break;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * _rotl - rotates the stack to the top
 * @stack: First element (head)
 * @line_number: is the line number where the instruction appears
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack != NULL)
	{
		tmp = (*stack)->n;
		add_dnodeint_end(&*stack, tmp);
		_pop(stack, line_number);
	}

}

/**
 * _rotr - rotates the stack to the bottom
 * @stack: First element (head)
 * @line_number: is the line number where the instruction appears
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack, *tmp;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (aux->next)
	{
		aux = aux->next;
	}
	tmp = aux->prev;
	aux->next = *stack;
	aux->prev = NULL;
	tmp->next = NULL;
	(*stack)->prev = aux;
	*stack = aux;
}
