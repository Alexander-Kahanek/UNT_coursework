/*
Author:		Alexander Kahanek (alexanderkahanek@my.unt.edu)
Date: 		26 SEP 2019
Instructor: 	Pradhumna Shrestha
Description:	Program prompts user for a movement, and outputs the movement the user made.
*/

#include <iostream>
using namespace std;

int main ()
{

enum Direction {UP='I', LEFT='J', RIGHT='L', DOWN='K'};
char userKey;

cout << "Enter direction to move (I=UP, J=LEFT, K=DOWN, L=RIGHT): ";
cin >> userKey;

if (userKey == UP)
{
	cout << "You moved UP!" << endl;
}
else if (userKey == LEFT)
{
	cout << "You moved LEFT!" << endl;
}
else if (userKey == RIGHT)
{
	cout << "You moved RIGHT!" << endl;
}
else if (userKey == DOWN)
{
	cout << "You moved DOWN!" << endl;
}
else
{
	cout << "Incorrect key entered." << endl;
}
	return 0;
}