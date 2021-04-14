//MAIN
/*
Name: Alexander Kahanek (ark0174)
Teacher: David Keathly
Date: 3/22/2020
*/
#include "main.h"

int main ()
{
	Drivers D; //creating main drivers class
	D.loadDrivers(); //loading drivers

	Passengers P; //creating main passengers class
	P.loadPassengers(); //loading passengers

	Rides R; //creating main rides class
	R.loadRides(); //loading rides

	
	//calling program header
	cout << "*******************************************************" << endl;
	cout << "** Welcome to the Mean Green Transportation Machine! **" << endl;
	cout << "*******************************************************" << endl;
	cout << "**   Here you can add Drivers, Passengers and Rides  **" << endl;
	cout << "**   to store locally. After you have at least one   **" << endl;
	cout << "**      Driver added you can begin adding Rides!     **" << endl;
	cout << "*******************************************************" << endl;
	cout << "**               Program Designed by:                **" << endl;
	cout << "**                Alexander Kahanek                  **" << endl;
	cout << "*******************************************************" << endl;
	cout << endl;

	int menu =1; //keeping track of menu
	while (menu != -1) //whenever user quits, it will jump out of loop
	{
		menu = PrintMainMenu(D, P, R);
	}

	char uc; //keeping track of user choice
	do
	{
		cout << "************************************************" << endl;
		cout << "Would you like to save your data before leaving?" << endl;
		cout << "y - yes, save data" << endl;
		cout << "n- no, do not save data" << endl;
		cin >> uc;
	} while (uc != 'y' & uc != 'n');

	if (uc == 'y')
	{cout << endl; Menu_x(D,P,R);} //calls menu that saves data
	else if (uc == 'n')
	{cout << endl << "**** NO DATA WAS SAVED ****" << endl;}

	return 0;
}

