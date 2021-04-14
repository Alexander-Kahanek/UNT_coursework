/*
Author:		Alexander Kahanek (alexanderkahanek@my.unt.edu)
Date: 		26 SEP 2019
Instructor: 	Pradhumna Shrestha
Description:	Program prompts the user for the integer month value, and tells the user what season that month is in.
*/

#include <iostream>
using namespace std;

int main ()
{

int userMonth;

//cout << "January=1, February=2, March=3, April=4, May=5, June=6" << endl << "July=7, August=8, September=9, October=10, November=11, December=12" << endl; //not needed
cout << "Please enter the integer number for the month: ";
cin >> userMonth;

switch (userMonth)
{
	case 1:
	case 2:
	case 12:
		cout << "The chosen month is considered Winter." << endl;
		break;

	case 3:
	case 4:
	case 5:
		cout << "The chosen month is considered Spring." << endl;
		break;
	case 6:
	case 7:
	case 8:
		cout << "The chosen month is considered Summer." << endl;
		break;
	case 9:
	case 10:
	case 11:
		cout << "The chosen month is considered Fall." << endl;
		break;
	default:
		cout << "Incorrect value for month was enetered." << endl;
		break;
	}
return 0;
}