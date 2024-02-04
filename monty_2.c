#include "monty.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");
	if (!file) {
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	// Initialize the global stack
	stack_t *global_stack = NULL;

	// Parse the file line by line and execute the instructions
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	while (getline(&line, &len, file) != -1) {
		line_number++;

		// Parse the opcode and arguments from the line
		char *opcode = strtok(line, " \t\n");
		if (!opcode || opcode[0] == '#') {
			// Ignore empty lines and comments
			continue;
		}

		// Find the corresponding function pointer for the opcode
		/*int found = 0;
		  for (size_t i = 0; i < sizeof(instructions) / sizeof(instruction_t); i++) {
		  if (strcmp(opcode, instructions[i].opcode) == 0) {
		  instructions[i].f(&global_stack, line_number);
		  found = 1;
		  break;
		  }
		  }

		  if (!found) {
		  fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		  exit(EXIT_FAILURE);
		  */
		if (strcmp(opcode, "push") == 0) {
			// Extract the integer argument from the line
			char *arg = strtok(NULL, " \t\n");
			if (!arg) {
				fprintf(stderr, "L%d: push requires an integer argument\n", line_number);
				exit(EXIT_FAILURE);
			}

			// Convert the argument to an integer
			int value = atoi(arg);

			// Call the push function with the extracted value
			push(&global_stack, line_number, value);
		} else {
			// Find the corresponding function pointer for other opcodes
			int found = 0;
			for (size_t i = 0; i < sizeof(instructions) / sizeof(instruction_t); i++) {
				if (strcmp(opcode, instructions[i].opcode) == 0) {
					instructions[i].f(&global_stack, line_number);
					found = 1;
					break;
				}
			}

			if (!found) {
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}

			// Clean up and close the file
			free(line);
			fclose(file);

			return EXIT_SUCCESS;
		}
	}
	}
