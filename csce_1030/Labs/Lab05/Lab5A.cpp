/*
Author:		Alexander Kahanek (alexanderkahanek@my.unt.edu)
Date: 		26 SEP 2019
Instructor: 	Pradhumna Shrestha
Description:	User inputs a string, program chooses a random index in the string and outputs what type of character is at the random index.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <cstring>

using namespace std;

int main ()
{
	string user_string;
	cout << "Please enter a string: "; getline(cin, user_string);

	srand(time(NULL));
	int random_place = rand() % (user_string.length());
	char string_char = user_string.at(random_place);

	if (user_string.length() >= 0)
	{
		if (isdigit(string_char))
		{
			cout << "String at index " << random_place << " is a digit." << endl; 
		}
		else if (isalpha(string_char))
		{
			cout << "String at index " << random_place << " is a alpha." << endl;
		}
		else if (isspace(string_char))
		{
			cout << "String at index " << random_place << " is a space." << endl;
		}
		else if (ispunct(string_char))
		{
			cout << "String at index " << random_place << " is a special character." << endl;
		}
		else
		{
			cout << "Error." << endl;
		}
	}

	return 0;
}