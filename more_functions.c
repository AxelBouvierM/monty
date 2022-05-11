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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
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

/**
 * _sub - subtracts the top element of the stack from the second top element
 * @stack: First element (head)
 * @line_number: is the line number where the instruction appears
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	int sub;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		sub = (*stack)->next->n - (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n = sub;
	}
}

/**
 * _div - divides the second top element of the stack by the top element
 * @stack: First element (head)
 * @line_number: is the line number where the instruction appears
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int div;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
	}
	div = (*stack)->next->n / (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = div;
}

/**
 * _mul - multiplies the second top element of the stack with the top
 * @stack: First element (head)
 * @line_number: is the line number where the instruction appears
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int mul;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	mul = (*stack)->next->n * (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = mul;
}
