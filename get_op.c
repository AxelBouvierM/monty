#include "monty.h"
/**
 * get_op - checks if the opcode exists and assigns the corresponding function
 * @file: File with instructions
 * @op: Struct with instructions
 * Return: 0 if succes
 */
int get_op(FILE *file, instruction_t op[])
{
	int count = 0, flag = 0;
	size_t buffer = 0;
	stack_t *stack = NULL;
	char *str = NULL, *token = NULL;
	unsigned int line_number = 0;

	while (1)
	{
		if (getline(&str, &buffer, file) == -1)
		{
			free(str);
			break;
		}
		line_number++;
		token = strtok(str, "\t\n ");
		count = 0, flag = 0;
		if (token)
		{
			if (token[0] == '#')
				continue;
			while (op[count].opcode != NULL)
			{
				if (strcmp(token, op[count].opcode) == 0)
				{
					op[count].f(&stack, line_number);
					flag = 1;
				}
				count++;
			}
			if (flag == 0)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
				free_dlistint(stack), free(str);
				fclose(file);
				exit(EXIT_FAILURE);
			}
		}
	}
	free_dlistint(stack);
	return (0);
}
