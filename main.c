#include "monty.h"

/**
 *  main - entry
 *  @argc: Number of args
 *  @argv: args
 *  Return: int
 */
int main(int argc, char *argv[])
{
	stack_t *head = NULL;
	char  *str = NULL, *op_arr[2], *tmp;
	size_t bufsize = 1024, line_count = 0;
	int result, cond = 1;
	void (*op_func)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	while (cond)
	{
		result = getline(&str, &bufsize, file);
		if (result == -1)
			break;
		line_count++;
		op_arr[0] = strtok(str, "\n ");
		if (op_arr[0] == NULL)
			_notin(&head, line_count);
		else if (strcmp("push", op_arr[0]) == 0)
		{
			tmp = strtok(NULL, "\n ");

			_push(&head, line_count, tmp);
		}
		else if (op_arr[0] != NULL && op_arr[0][0] != '#')
		{
			op_func = get_op(op_arr[0], line_count, &head);

			if (op_func == NULL && line_count == 0)
			{
				fprintf(stderr, "L%ld: unknown instruction %s\n",
					line_count, op_arr[0]), exit(EXIT_FAILURE);
			}
		op_func(&head, line_count);
		}
	}
	fclose(file), free(str), free_stck(head);
	return (0);
}
