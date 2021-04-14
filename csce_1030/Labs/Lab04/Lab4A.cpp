/*
Author:		Alexander Kahanek (alexanderkahanek@my.unt.edu)
Date: 		26 SEP 2019
Instructor: 	Pradhumna Shrestha
Description:	Program compares the user enetered number, with a randomly generated number.
		Stating if the random number is less than, greater than, or equal to the user entered number.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main ()
{

int userNum; //user enetered number on [50-100]
int randNum; //randomly generated number on [50-100]

cout << "Please enter a number between 50 and 100, inclusive: ";
cin >> userNum;

srand(time(NULL));
randNum = rand () % 51 + 50;

cout << "Your randomly generated number is: " << randNum << endl;

if ((userNum < 50) || (userNum > 100))
{
	cout << "Incorrect number entered." << endl;
}
else if (randNum < userNum) 
{
	cout << "The random number is less than your number." << endl;
}
else if (randNum > userNum)
{
	cout << "The random number is more than your number." << endl;
}
else //last option is the (randNum == userNum)
{
	cout << "The random number is equal to your number." << endl;
}

	return 0;
}