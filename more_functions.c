#include "monty.h"
/**
 * _add - adds the top two elements of the stack
 * @stack: First element (head)
 * @line_number: is the line number where the instruction appears
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L<%d>: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		sum = (*stack)->n + (*stack)->next->n;
		_pop(stack, line_number);
		(*stack)->n = sum;
	}
}

/**
 * _nop - doesn’t do anything
 * @stack: First element (head)
 * @line_number: is the line number where the instruction appears
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
