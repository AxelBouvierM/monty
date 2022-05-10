#include "monty.h"
/**
 * main - Function that reads the file and executes the functions
 * @argc: Numbers of elements
 * @argv: Elements
 * Return: 0 if succes
 */
int main(int argc, char *argv[])
{
	FILE *file;

	instruction_t op[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{NULL, NULL}
	};
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	get_op(file, op);
	fclose(file);
	return (0);
}
