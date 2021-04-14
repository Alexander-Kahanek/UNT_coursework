/*
Author:		Alexander Kahanek (alexanderkahanek@my.unt.edu)
Date: 		5 DEC 2019
Instructor: 	Pradhumna Shrestha
Description:	Reads user file of numbers, converts meters to feet, outputs feet onto new file
*/


#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

#define PI 3.14159
#define METERS_TO_FEET 3.28084
#define convert(x) x*METERS_TO_FEET

int main (int argc,char **argv)
{

	if (argc != 2)
	{
		printf("Please enter file you want to create.\n");
		exit(EXIT_FAILURE);
	}

	//printf("%s\n", argv[1]);

	FILE *fin;
	fin = fopen("meters.txt", "r");

	if (fin == NULL)
		{
			printf("unable to open file\n");
			exit(EXIT_FAILURE);
		}

	FILE *fout;
	fout = fopen(argv[1], "w");

	if (fout == NULL)
		{
			printf("unable to create file\n");
			exit(EXIT_FAILURE);
		}

	float x;
	while (fscanf(fin, "%f", &x) == 1)
	{
		
		x= convert(x);
		fprintf(fout, "%.3f\n", x);
	}


	fclose(fin);
	fclose(fout);

	return 0;
}