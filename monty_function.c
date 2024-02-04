#define _GNU_SOURCE
#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * Return: Void
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *h = *stack, *ptr;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	if (h && h->next)
	{
		ptr = h->next;
		if (ptr->next)
			ptr->next->prev = h;
		h->next = ptr->next;
		ptr->prev = NULL;
		ptr->next = h;
		h->prev = ptr;
		*stack = ptr;
	}
}

/**
 * pint - print the latest element in the stack
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * Return: Void
 */
void pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
	line_num++;
}

/**
 * add - make the sum of the 2 first elements
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * Return: Void
 */
void add(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;
	int sum = 0;
	int i = 0;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	while (current != NULL)
	{
		current = current->next;
		i++;
	}

	if (i < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	current = (*stack)->next;

	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	free(*stack);
	*stack = current;
}
