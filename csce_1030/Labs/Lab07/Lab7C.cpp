/*
Author:		Alexander Kahanek (alexanderkahanek@my.unt.edu)
Date: 		24 OCT 2019
Instructor: 	Pradhumna Shrestha
Description:	Compares user input color, and if user inputs "red", "blue", "black" change to "yellow".
		Everything else change to "cyan".
*/

#include <iostream>
#include <cstring>

using namespace std;

void string_replace (char userInput[], char option1[], char option2[]);

int main ()
{
	char userInput[10] = {0}; //array for user input
	char option1[] = "yellow"; 
	char option2[] = "cyan"; 

	cout << "Enter a color: ";
	cin.getline(userInput, 9); //needs to stop at 9 to save room for null character

	string_replace(userInput, option1, option2); //func call to replace userInput with yellow or cyan 

	return 0;
}

void string_replace (char userInput[], char option1[], char option2[])
{

	if (strcmp(userInput, "red") == 0 || strcmp(userInput, "blue") == 0 || strcmp(userInput, "black") == 0)
	{	
		strcpy (userInput, option1); // if these are true, replace with yellow
	}
	else
	{
		strcpy(userInput, option2); // if these are false, replace with cyan
	}

	cout << "It has been changed to " << userInput << endl; //output in function
}