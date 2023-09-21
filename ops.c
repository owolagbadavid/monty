#include "monty.h"

/**
 * _push - push to stck
 * @stack: pointer to the top of the stack
 * @line_number: number
 * @val: value
 */
void _push(stack_t **stack, unsigned int line_number, char *val)
{

	stack_t *new_top;

	if (val == NULL || isnumber(val) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(file);
		free_stck(*stack);
		exit(EXIT_FAILURE);
		if (isnumber(val) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(file);
			free_stck(*stack);
			exit(EXIT_FAILURE);
		}
	}
	new_top = malloc(sizeof(stack_t));
	if (new_top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	new_top->n = atoi(val);
	new_top->next = NULL;
	new_top->prev = NULL;
	if (*stack)
	{
		new_top->next = *stack;
		(*stack)->prev = new_top;
		*stack = new_top;
	}
	*stack = new_top;
}

/**
 *  isnumber - if is number
 *  @str: string
 *  Return: int
 */

int isnumber(char *str)
{

	int i = 0;


	if (str[i] == '-')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
		{
			return (0);
		}
		i++;
	}

	return (1);
}

/**
 *  _notin - nothng
 *  @stack: stack head
 *  @line_count: line count
 */
void _notin(stack_t **stack, unsigned int line_count)
{

	(void) stack;
	(void) line_count;
}

/**
 *  free_stck - free stack
 *  @stack: stack
 */
void free_stck(stack_t *stack)
{
	if (stack)
	{
		free_stck(stack->next);
		free(stack);
	}
}

/**
 * get_op - get op
 * @op_f: str
 * @l: line
 * @stak: stack
 * Return: func
 */
void (*get_op(char *op_f, unsigned int l, stack_t **stak))(stack_t**, unsigned int)
{
	int count;

	instruction_t ops[] = {
		{"pall", _pall},
		{"add", _add},
		{"pint", _pint},
		{"swap", _swap},
		{"pop", _pop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"nop", _notin},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{NULL, NULL}
	};

	for (count = 0; ops[count].opcode != NULL; count++)
	{
		if (strcmp(ops[count].opcode, op_f) == 0)
		{
			return (ops[count].f);
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", l, op_f);
	fclose(file);
	free_stck(*stak);
	exit(EXIT_FAILURE);
}
