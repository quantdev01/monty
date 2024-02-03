#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	int value;

	if (!value)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *newnode = malloc(sizeof(stack_t));
	
	if (!newnode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newnode->n = value;
	newnode->next = *stack;
	*stack = newnode;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	if (temp == NULL)
		printf("Null pointer\n");
	while (temp != 0)
	{
		printf("%d\n", temp->n);
		temp  = temp->next;
	}
}
