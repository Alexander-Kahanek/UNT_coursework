//functions.cpp
/*
Name: Alexander Kahanek (ark0174)
Teacher: David Keathly
Date: 3/22/2020
*/

#include "main.h"

int PrintMainMenu(Drivers &D, Passengers &P, Rides &R)
{ //prints main menu
	char uc;
	
	do {
		cout << "**************************" << endl;
		cout << "What would you like to do?" << endl;
		cout << "d - manage drivers" << endl;
		cout << "p - manage passengers" << endl;
		cout << "r - manage rides" << endl;
		cout << "g - get info for a Driver, Passenger, or Ride" << endl;
		cout << "s - search and print" << endl;
		cout << "x - save all current data" << endl;
		cout << "l - reload most recent data" << endl;
		cout << "q - quit" << endl;

		cin >> uc;
		cout << endl;
	} while (uc != 'd' & uc != 'p' & uc != 'r' & uc != 'g' & uc != 's' & uc != 'x' & uc != 'l' & uc != 'q');

	switch (uc)
	{
		case 'd': //manage drivers
			Menu_d(D);
			cout << endl;
			break;
		case 'p': //manage passengers
			Menu_p(P);
			cout << endl;
			break;
		case 'r': //manage rides
			Menu_r(D,P,R);
			cout << endl;
			break;
		case 'g': //get info
			Menu_g(D,P,R);
			cout << endl;
			break;
		case 's': //search and print
			Menu_s(D,P,R);
			cout << endl;
			break;
		case 'x': //save
			Menu_x(D,P,R);
			cout << endl;
			break;
		case 'l': //load
			Menu_l(D,P,R);
			cout << endl;
			break;
		case 'q': //quits program
			return -1;
	}
}

void Menu_d(Drivers &D)
{ //manage drivers
	char uc;

	do
	{
		cout << "*************************************" << endl;
		cout << "What would you like to do in drivers?" << endl;
		cout << "a - add a driver" << endl;
		cout << "e - edit a driver" << endl;
		cout << "d - delete a driver" << endl;
		cout << "q - go back a menu" << endl;

		cin >> uc;
	} while (uc != 'a' & uc != 'e' & uc != 'd' & uc != 'q');

	int ID;

	switch (uc)
	{
		case 'a':
			D.addDriver();
			break;
		case 'e':
			ID = FindDriver(D);
			D.editDriver(ID);
			break;
		case 'd':
			ID = FindDriver(D);
			if (ID != 0)
			{ D.deleteDriver(ID); }
			break;
		case 'q':
			cout << endl;
			break;

	}
}

void Menu_p(Passengers &P)
{ //manage passengers
	char uc;

	do
	{
		cout << "*************************************" << endl;
		cout << "What would you like to in passengers?" << endl;
		cout << "a - add a passenger" << endl;
		cout << "e - edit a passenger" << endl;
		cout << "d - delete a passenger" << endl;
		cout << "q - go back a menu" << endl;

		cin >> uc;
	} while (uc != 'a' & uc != 'e' & uc != 'd' & uc != 'q');

	int ID;

	switch (uc)
	{
		case 'a':
			P.addPassenger();
			break;
		case 'e':
			ID = FindPassenger(P);
			P.editPassenger(ID);
			break;
		case 'd':
			ID = FindPassenger(P);
			if (ID != 0)
			{ P.deletePassenger(ID); }
			break;
		case 'q':
			cout << endl;
			break;
	}
}

void Menu_r(Drivers &D, Passengers &P, Rides &R)
{ //manage rides
	char uc;

	do
	{
		cout << "********************************" << endl;
		cout << "What would you like to in rides?" << endl;
		cout << "a - add a ride" << endl;
		cout << "e - edit a ride" << endl;
		cout << "d - delete a ride" << endl;
		cout << "u - update all rides status" << endl;
		cout << "c - cancel a ride" << endl;
		cout << "x - delete all cancelled and completed rides" << endl;
		cout << "q - go back a menu" << endl;

		cin >> uc;
	} while (uc != 'a' & uc != 'e' & uc != 'd' & uc != 'u' & uc != 'c' & uc != 'x' & uc != 'q');

	int ID;

	switch (uc)
	{
		case 'a':
			R.addRide(D,P);
			break;
		case 'e':
			ID = FindRide(D,P,R);
			R.editRide(ID);
			break;
		case 'd':
			ID = FindRide(D,P,R);
			if (ID != 0)
			{ R.deleteRide(ID); }
			break;
		case 'u':
			R.update_all_status();
			cout << endl << "***** UPDATED ALL RIDE STATUS *****" << endl;
			break;
		case 'c':
			ID = FindRide(D,P,R);
			if (ID != 0 )
			{ R.cancel_ride(ID); }
			break;
		case 'x':
			R.update_all_status();
			R.delete_2_3(0);
			break;
		case 'q':
			cout << endl;
			break;
	}
}

void Menu_g(Drivers &D, Passengers &P, Rides &R)
{ //get info //print a single item
	char uc;

	do
	{
		cout << "************************************" << endl;
		cout << "What would you like to get info for?" << endl;
		cout << "d - Find a driver" << endl;
		cout << "p - Find a passenger" << endl;
		cout << "r - Find a ride" << endl;
		cout << "q - go back a menu" << endl;

		cin >> uc;
	} while (uc != 'd' & uc != 'p' & uc != 'r' & uc != 'q');

	int ID;

	switch (uc)
	{
		case 'd':
			ID = FindDriver(D);
			if (ID != 0 )
			{ D.print_a_Driver(ID); }
			//print all rides
			break;
		case 'p':
			ID = FindPassenger(P);
			if (ID != 0 )
			{ P.print_a_Passenger(ID); }
			//print all rides
			break;
		case 'r':
			R.update_all_status();
			ID = FindRide(D,P,R);
			if (ID != 0 )
			{ R.print_a_Ride(ID); }
			break;
		case 'q':
			cout << endl;
			break;
	}
}

int FindDriver(Drivers &D)
{ //function for finding any driver
	char uc;	

	do
	{
		cout << endl;
		cout << "****************" << endl;
		cout << "i - Find a driver based off id" << endl;
		cout << "n - Find a driver based off name" << endl;
		cout << "q - go back a menu" << endl;

		cin >> uc;
	}while (uc != 'i' & uc != 'n' & uc != 'q');

	int ID;
	int foundID;


	if (uc == 'i')
	{
		cout << endl << "Please enter the drivers ID number: ";
		cin >> ID;
		foundID = D.findByID(ID);
		return foundID;
	}
	else if (uc == 'n')
	{
		string name;
		cout << endl << "Please enter the drivers name: ";
		cin.ignore();
		getline(cin, name);
		foundID = D.findByName(name);
		return foundID;
	}
	else
	{ cout << endl; return 0; }

}

int FindPassenger(Passengers &P)
{ //function for finding any passenger
	char uc;	

	do
	{
		cout << endl;
		cout << "****************" << endl;
		cout << "i - Find a passenger based off id" << endl;
		cout << "n - Find a passenger based off name" << endl;
		cout << "q - go back a menu" << endl;

		cin >> uc;
	}while (uc != 'i' & uc != 'n' & uc != 'q');

	int ID;
	int foundID;

	if (uc == 'i')
	{
		cout << endl << "Please enter the passengers ID number: ";
		cin >> ID;
		foundID = P.findByID(ID);
		return foundID;
	}
	else if (uc == 'n')
	{
		string name;
		cout << endl << "Please enter the passengers name: ";
		cin.ignore();
		getline(cin, name);
		ID = P.findByName(name);
		return ID;
	}
	else
	{ cout << endl; return 0; }
}

int FindRide(Drivers &D, Passengers &P, Rides &R)
{ //function for finding any ride
	char uc;	

	do
	{
		cout << endl;
		cout << "****************" << endl;
		cout << "i - Find a Ride based off id" << endl;
		cout << "d - Find a Ride based off driver" << endl;
		cout << "p - Find a ride based off a passengers" << endl;
		cout << "q - go back a menu" << endl;

		cin >> uc;
	}while (uc != 'i' & uc != 'd' & uc != 'q' & uc != 'p');

	int ID;
	int foundID;

	if (uc == 'i')
	{
		cout << endl << "Please enter the rides ID number: ";
		cin >> ID;
		foundID = R.findByID(ID);
		return foundID;
	}
	else if (uc == 'd')
	{
		ID = R.findByDriver(D);
		return ID;
	}
	else if (uc == 'p')
	{
		ID = R.findByPassenger(P);
		return ID;

	}
	else
	{ cout << endl; return 0; }

}

void Menu_s(Drivers &D, Passengers &P, Rides &R)
{ //print all items, or specific sets of items
	char uc;	

	do
	{
		cout << "*****************************" << endl;
		cout << "What would you like to print?" << endl;
		cout << "d - Print all Drivers" << endl;
		cout << "p - Print all Passengers" << endl;
		cout << "r - search Rides" << endl;
		cout << "q - go back a menu" << endl;

		cin >> uc;
	}while (uc != 'd' & uc != 'p' & uc != 'q' & uc != 'r');

	if (uc == 'd')
	{D.printAllDrivers();}
	else if (uc == 'p')
	{P.printAllPassengers();}
	else if (uc == 'r')
	{
		char ruc;
		do
		{
		cout << endl;
		cout << "***************************************" << endl;
		cout << "What would you like to search in rides?" << endl;
		cout << "a - print all rides" << endl;
		cout << "d - print all rides for a driver" << endl;
		cout << "p - print all rides for a passenger" << endl;
		cout << "s - print all rides by a certain status" << endl;
		cout << "q - quit" << endl;
		cin >> ruc;
		} while (ruc != 'q' & ruc != 'a' & ruc != 'd' & ruc != 'p' & ruc != 's');

		R.update_all_status();
		int ID;
		switch (ruc)
		{
			case 'a':
				R.printAllRides();
				break;
			case 'd':
				ID = FindDriver(D);
				if (ID == 0) {return;}
				R.print_for_driver(ID);
				break;
			case 'p':
				ID = FindPassenger(P);
				if (ID == 0) {return;}
				R.print_for_passenger(ID);
				break;
			case 's':
				R.print_by_status();
				break;
			case 'q':
				break;
		}
	}
	else
	{return;}

}

void Menu_x(Drivers &D, Passengers &P, Rides &R)
{ //save everything
	D.saveDrivers();
	P.savePassengers();
	R.saveRides();

	cout << "**** ALL DATA HAS BEEN SAVED ****" << endl;

}

void Menu_l(Drivers &D, Passengers &P, Rides &R)
{ //load everything
	char uc;

	do
	{
		cout << "***********************************************" << endl;
		cout << "Loading all data will erase any unsaved data..." << endl;
		cout << "Are you sure you want to continue?" << endl;
		cout << "y - yes, load my most recent data." << endl;
		cout << "n - no, go back to previous menu." << endl;

		cin >> uc;
	}while (uc != 'y' & uc != 'n');

	if (uc == 'y')
	{
		D.loadDrivers();
		P.loadPassengers();
		R.loadRides();
		cout << endl << "All data has been loaded!" << endl;
	}
	else if (uc == 'n')
	{
		cout << endl << "No data was loaded, going back to main menu." << endl;
	}

}
