/*
Author:		Alexander Kahanek (alexanderkahanek@my.unt.edu)
Date: 		26 SEP 2019
Instructor: 	Pradhumna Shrestha
Description:	Prompts user for a string, program counts number of Digits, Alphas, Spaces, and Special Characters in the users string, 
		then program outputs those values.
*/


#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int main ()
{
	string user_string;
	cout << "Please enter a string: "; getline(cin, user_string);

	int numDigit=0;
	int numAlpha=0;
	int numSpace=0;
	int numPunct=0;
	
	int i=0;

	while (i<user_string.length())
	{
		
		
		char string_char = user_string.at(i);

		if (isdigit(string_char))
		{
			++numDigit;
		}
		else if (isalpha(string_char))
		{
			++numAlpha;
		}
		else if (isspace(string_char))
		{
			++numSpace;
		}
		else if (ispunct(string_char))
		{
			++numPunct;
		}
		else
		{
			cout << "Error." << endl;
		}
	
		++i;
	}
	
	cout << "Your string has "<< numDigit << " Digits." << endl;
	cout << "Your string has "<< numAlpha << " Alphas." << endl;
	cout << "Your string has "<< numSpace << " Spaces." << endl;
	cout << "Your string has "<< numPunct << " Special Characters." << endl;

	return 0;
}