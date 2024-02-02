#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

int main(int index, char *argv[])
{
	const char *filename = argv[1];

	int i = 0;
	int j = 0;

	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		perror("Error opening the file\n");
		return (1);
	}

	char filelines[100];

	while (fgets(filelines, sizeof(filelines), file) != NULL)
	{
		while (i < 100)
		{
			char *itochar = (char) i;
			if (strstr(filelines, "push") != NULL /*&& strstr(filelines, itochar) != NULL*/)
			{
				printf("Yes it pull is there [%d]\n", i);
			}
			i++;
		}
	}
	printf("i = %d\n", i);
	/*for (j = 0; j < i; j++)
	  printf("This is my new array %s\n", new[j]);*/
	fclose(file);
	return (0);
}
