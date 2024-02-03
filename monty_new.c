#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

void push(int value) {
	if (top == STACK_SIZE - 1) {
		fprintf(stderr, "Error: Stack overflow\n");
		exit(EXIT_FAILURE);
	}
	stack[++top] = value;
}

void pall() {
	int i;
	for (i = top; i >= 0; i--) {
		printf("%d\n", stack[i]);
	}
}

int main(int argc, char *argv[]) {
	// Check if a file name is provided
	if (argc != 2) {
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// Open the file for reading
	FILE *file = fopen(argv[1], "r");
	if (file == NULL) {
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	char opcode[4];
	int value;

	// Read and process each line in the file
	while (fscanf(file, "%3s", opcode) == 1) {
		if (strcmp(opcode, "push") == 0) {
			// Handle push operation
			if (fscanf(file, "%d", &value) != 1) {
				fprintf(stderr, "Error: usage: push integer\n");
				exit(EXIT_FAILURE);
			}
			push(value);
		} else if (strcmp(opcode, "pall") == 0) {
			// Handle pall operation
			pall();
		} else {
			fprintf(stderr, "Error: unknown opcode '%s'\n", opcode);
			exit(EXIT_FAILURE);
		}
	}

	// Close the file
	fclose(file);

	return 0;
}

