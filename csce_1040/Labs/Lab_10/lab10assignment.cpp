/*
Name: Alexander Kahanek
Professor: David Keathly
Date: 4/10/20
Assignment: Lab 10 Recursion
*/

#include <iostream>
#include <iomanip>

using namespace std;

int Liar_Liar(int n, int val, int vec[]);


int main()
{
	int n; //the n
	int SIZE = 23; //size of array, and bounds for n
	
	do{//grabbing n from user
	cout << "Please enter a n for the Liar-Liar sequence [1,23]: ";
	cin >> n;
	} while(n<1 || n>23); //[1,23]

	int vec[SIZE]; //array for output

	Liar_Liar(n,0, vec);

	for (int i=0; i<n; ++i) //for output
	{
		cout << "Liar-Liar("<< setw(2) <<i+1 << ") =" << setw(13) << vec[i] << endl;
	}

	return 0;
}

int Liar_Liar(int n, int val, int vec[])//need to pass vector for output..
{ //recursive function

	if (n == 1){
		val= -1;
	}
	else if (n==2){
		val = Liar_Liar(n-1, val, vec); //val = -1, same as n-1
	}
	else if (n > 2){
		val = 2*( Liar_Liar(n-1, val, vec) + Liar_Liar(n-2, val, vec) ); //equation
	}

	vec[n-1]=val;//assign to vector for output..

	return(val); //send back val
}