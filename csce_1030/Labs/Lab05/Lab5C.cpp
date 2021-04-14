/*
Author:		Alexander Kahanek (alexanderkahanek@my.unt.edu)
Date: 		26 SEP 2019
Instructor: 	Pradhumna Shrestha	
Description:	User inputs number on [0,100], program calculates sum of numbers from [0,user number] and outputs all numbers with sum to user.
*/


#include <iostream>
using namespace std;

int main ()
{
	int userNum;
	cout << "Please enter a number between [0,100]: "; cin >> userNum;

	int sum=0;
	if (userNum >= 0 && userNum <= 100)
	{	
		for (int i=0; i<=userNum; ++i)
		{
				sum += i;
			if (i<userNum)
			{
				cout << i << "+";
			}
			else
			{
				cout << i;
			}
		}
	}
	else
	{
		cout << "Wrong number entered." << endl;
	}

	cout <<"= "<< sum<< endl;

	return 0;
}