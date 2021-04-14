//main.h
/*
Name: Alexander Kahanek (ark0174)
Teacher: David Keathly
Date: 3/22/2020
Program Algorithm:
* Loads in previous save data
	- if no save data, notify user
* Loop main menu, until user quits
* when user enters submenu, when they exit they go to main menu
* Drivers -> Driver
* Passengers -> Passenger
* Rides -> Ride
	- a ride will hold the id of the driver, and id of the passenger(s)
* Add / Edit / Delete Class
* Print class based on user requirements
* Save data at end by asking if user wants, will not save when program crashes.
	- THIS IS INTENTIONAL, incase user makes a mistake they can backtrack
	- Also allow user to save data from main menu
* one data file per class, no multiple save files allowed
* all time is based off user time
*/

#include <iostream>
#include "rides.h" //only need this, as everything else gets shuffled in through rides.h

using namespace std;


void Menu_d(Drivers &D);
void Menu_p(Passengers &P);
void Menu_r(Drivers &D, Passengers &P, Rides &R);
void Menu_g(Drivers &D, Passengers &P, Rides &R);
void Menu_s(Drivers &D, Passengers &P, Rides &R);
void Menu_x(Drivers &D, Passengers &P, Rides &R);
void Menu_l(Drivers &D, Passengers &P, Rides &R);
int FindDriver(Drivers &D);
int FindPassenger(Passengers &P);
int FindRide(Drivers &D, Passengers &P, Rides &R);
int PrintMainMenu(Drivers &D, Passengers &P, Rides &R);
