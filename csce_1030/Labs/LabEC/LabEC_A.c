/*
Author:		Alexander Kahanek (alexanderkahanek@my.unt.edu)
Date: 		5 DEC 2019
Instructor: 	Pradhumna Shrestha
Description:	Reads user file, counts number of characters, words, and lines.
*/

#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

int main ()
{
	FILE *fp;
	char filename[50];
	char input;
	int chars=0, words=0, lines=0;

	printf("Please enter file name: "); scanf("%s", filename);

	fp = fopen(filename, "r");

	if (fp == NULL)
	{
		printf("unable to open file\n");
		exit(EXIT_FAILURE);
	}

	input = getc(fp);
	while (input != EOF)
	{
		if (input != ' ' && input != '\n'); //must be a char
		{
			++chars;
		}

		if (input == '\n') //must be a line
		{
			++lines;
		}

		if (input == ' ' || input == '\t' || input == '\n')//must have been a word previous
		{
			++words;
		}

		//printf("%c", input);

		input = getc(fp);
	}
	
	printf("The number of characters is: %i\n", chars);
	printf("The number of words is: %i\n", words);
	printf("The number of lines is: %i\n", lines);
	

	fclose(fp);
	return 0;
}