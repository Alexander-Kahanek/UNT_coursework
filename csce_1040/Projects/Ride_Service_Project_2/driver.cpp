//driver.cpp
/*
Name: Alexander Kahanek (ark0174)
Teacher: David Keathly
Date: 3/22/2020
*/

#include <iostream>
#include "driver.h"
using namespace std;

Driver::Driver()
{
	ID = 0;
	name = "none";
	vehicle = "none";
	veh_cap = 0;
	handicapped = 0;
	pets = 0;
	rating = 0.0;
	available = 1;
	notes = "none";
}

void Driver::setID(int i) {ID = i;}
void Driver::setName(string s) {name = s;}
void Driver::setVehicle(string s) {vehicle = s;}
void Driver::setVeh_Cap(int i) {veh_cap = i;}
void Driver::setHandicapped(bool b) {handicapped = b;}
void Driver::setPets(bool b) {pets = b;}
void Driver::setRating(float f) {rating = f;}
void Driver::setAvailable(bool b) {available = b;}
void Driver::setNotes(string s) {notes = s;}

int Driver::getID() {return ID;}
string Driver::getName() {return name;}
string Driver::getVehicle() {return vehicle;}
int Driver::getVeh_Cap() {return veh_cap;}
bool Driver::getHandicapped() {return handicapped;}
bool Driver::getPets() {return pets;}
float Driver::getRating() {return rating;}
bool Driver::getAvailable() {return available;}
string Driver::getNotes() {return notes;}

void Driver::editDriver()
{ //edits a single driver
	char uc;	

	do 
	{
		this->printDriver();
		cout << endl;
		cout << "****************" << endl;
		cout << "What would you like to edit?" << endl;
		cout << "n - name" << endl;
		cout << "v - vehicle" << endl;
		cout << "c - vehicle capacity" << endl;
		cout << "h - handicapped status" << endl;
		cout << "p - pet status" << endl;
		cout << "r - rating" << endl;
		cout << "a - availability" << endl;
		cout << "x - notes" << endl;
		cout << "q - quit editing" << endl;
		
		cin >> uc;

		string tempstring;
		int tempint;
		char huc;
		char puc;
		float tempfloat;
		cout << endl;
		switch (uc)
		{
			case 'n':
				cout << "Please enter the drivers new name: ";
				cin.ignore();
				getline(cin, tempstring);
				name = tempstring;
				break;
			case 'v':
				cout << "Please enter the drivers new vehicle: ";
				cin.ignore();
				getline(cin, tempstring);
				vehicle = tempstring;
				break;
			case 'c':
				cout << "Please enter the drivers new vehicle capacity: ";
				cin >> tempint;
				veh_cap = tempint;
				break;
			case 'h':
				do
				{
					cout << "****************" << endl;
					cout << "Is the driver able to take handicapped passengers?" << endl;
					cout << "y - yes" << endl;
					cout << "n - no" << endl;
					cin >> huc;
				} while (huc != 'y' & huc != 'n');

				if (huc == 'y')
				{ handicapped = 1; }
				else
				{ handicapped = 0; }
				break;
			case 'p':
				do
				{
					cout << "****************" << endl;
					cout << "Is the driver able to take pets?" << endl;
					cout << "y - yes" << endl;
					cout << "n - no" << endl;
					cin >> puc;
				} while (puc != 'y' & puc != 'n');

				if (puc == 'y')
				{ pets = 1; }
				else
				{ pets = 0; }
				break;
			case 'r':
				do
				{
					cout << "Please enter drivers rating on a scale of 0 - 10: ";
					cin >> tempfloat;
					}while(tempfloat <0 || tempfloat >10);
				rating = tempfloat;
				break;
			case 'a':
				char auc;
				do
				{
					cout << "Is your driver currently available?" << endl;
					cout << "y - yes driver is available" << endl;
					cout << "n - no, driver is not available" << endl;
					cin >> auc;
				} while (auc != 'y' & auc != 'n');

				if (auc == 'y') {available = 1;}
				if (auc == 'n') {available = 0;}
				break;
			case 'x':
				cout << "Please enter the drivers new notes: ";
				cin.ignore();
				getline(cin, tempstring);
				notes = tempstring;
				break;
			case 'q':
				break;
			default:
				cout << "Incorrect input, please try again." << endl;
				break;
		}
	} while (uc != 'q'); //loop until user is done editing
}

void Driver::printDriver()
{ //print driver
	cout << endl << "*****" << endl;
	cout << "Driver ID: " << ID << endl;
	cout << "Driver Name: " << name << endl;
	cout << "Driver Vehicle: " << vehicle << endl;
	cout << "Vehicle Capacity: " << veh_cap << endl;
	
	cout << "Availablility: ";
	if (available == 0) {cout << "NOT AVAILABLE" << endl;}
	else if (available ==1) {cout << "YES AVAILABLE" << endl;}	

	cout << "Handicapped Accomodations: ";
	if (handicapped == 0) {cout << "NO" << endl;}
	else if (handicapped ==1) {cout << "YES" << endl;}

	cout << "Pet Accomodations: ";
	if (pets == 0) {cout << "NO" << endl;}
	else if (pets ==1) {cout << "YES" << endl;}

	cout << "Driver Rating: " << rating << endl;
	//cout << "available: " << available << endl; //can be used for schedule if fixed
	cout << "Driver Notes: " << notes << endl;

}

void Driver::operator = (const Driver &D )
{ //overloads =
	ID = D.ID;
	name = D.name;
	vehicle = D.vehicle;
	veh_cap = D.veh_cap;
	handicapped = D.handicapped;
	pets = D.pets;
	rating = D.rating;
	notes = D.notes;
	available = D.available;
}
