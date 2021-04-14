/*
Author:		Alexander Kahanek (alexanderkahanek@my.unt.edu)
Date: 		24 OCT 2019
Instructor: 	Pradhumna Shrestha
Description:	Generates two random numbers, swaps the numbers, subtracts the numbers.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int subtract ( );
void swap (int& a, int& b);

int main ()
{
	int value = subtract(); // store value from functions

	cout << "The difference between two random numbers is: " << value<< endl;

	return 0;
}

int subtract ( ) //func for generating two random numbers and subtracting them
{

srand(time(NULL));
int a = rand() % 30 +1; // rand from [1, 30]
int b = rand() % 61 +40; // rand from [40, 100]

cout << "before swap: " << endl;
cout << "a= " << a << endl;
cout << "b= " << b << endl; 

swap (a,b); // calls to swap function

cout << "after swap: " << endl;
cout << "a= " << a << endl;
cout << "b= " << b << endl; 

return (a-b);
}

void swap (int& a, int& b) // swaps any two variables
{
	int temp=0;
	temp = a;
	a=b;
	b=temp;
}