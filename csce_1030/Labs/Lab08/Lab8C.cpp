/*
Author:		Alexander Kahanek (alexanderkahanek@my.unt.edu)
Date: 		7 NOV 2019
Instructor: 	Pradhumna Shrestha
Description:	Computes factorial for a user enetered number
*/

#include <iostream>
using namespace std;

int main()
{
	int user_num, factorial;
	cout << "Enter the number: ";
	cin >> user_num;
	
	factorial = 1;
	for (int i = 1; i <= user_num; ++i)
	{
		factorial = factorial * i;
	}

	cout << "Factorial of " << user_num << " is " << factorial << "." << endl;

	return 0;
}