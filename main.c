#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	FILE *fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open fie %s\n", argv[1]);
			exit(EXIT_FAILURE);
	}

	global = NULL;

	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	while (geline(&line, &len, fp) != - 1)
	{
		line_number++;
	}

	free(line);
	fclode(fp);

	return EXIT_SUCCESS;
}
