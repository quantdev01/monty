#ifndef MONTY_H
#define MONTY_H
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *global_stack;
//extern instruction_t instructions[];


void push(stack_t **stack, unsigned int line_number, int value);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

void push(stack_t **stack, unsigned int line_number, int value)
{
	stack_t *temp = *stack;
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

	newnode->prev = NULL;
	newnode->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = newnode;
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

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	// Add more instructions as needed
};

#endif
