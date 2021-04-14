/*
Author:		Alexander Kahanek (alexanderkahanek@my.unt.edu)
Date: 		17 OCT 2019
Instructor: 	Pradhumna Shrestha
Description:	Gets string from user, checks if individual character is a vowel, outputs all vowels up to 5
*/

#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
	const int N=6;
	string userSTR;
	char vowels[N];
	int count=0;

	cout << "Please enter a string: "; getline(cin, userSTR); // cin for user entered string
	
	for (int i=0; i<userSTR.length(); ++i) // loop for going through each character in string
	{
		if (isalpha(userSTR.at(i))) // checks if each character is a letter
		{
			if (userSTR.at(i) == 'a' || userSTR.at(i) == 'e' || userSTR.at(i) == 'i' || userSTR.at(i) == 'o' || userSTR.at(i) == 'u') //checks if lowercase vowle
			{
				if (count < 5) //limiter for number of vowels we take
				{
					vowels[count] = userSTR.at(i);
					++count;
				}
			}
			else if (userSTR.at(i) == 'A' || userSTR.at(i) == 'E' || userSTR.at(i) == 'I' || userSTR.at(i) == 'O' || userSTR.at(i) == 'U') //checks if uppercase vowel
			{
				if (count < 5) //limiter for number of vowels we take
				{
					vowels[count] = userSTR.at(i);
					++count;
				}
			}

		}
		
			
		
	}
	
	for (int i=0; i < count; ++i) //loop for display vowels
	{
		cout << vowels[i] << endl;
	}




	return 0;
}