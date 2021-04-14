//passenger.cpp
/*
Name: Alexander Kahanek (ark0174)
Teacher: David Keathly
Date: 3/22/2020
*/

#include <iostream>
#include "passenger.h"
using namespace std;


Passenger::Passenger()
{
	ID = 0;
	name = "none";
	pay_pref = "none";
	handicapped = 0;
	pets = 0;
	rating = 0.0;
}

void Passenger::setID(int i) {ID = i;}
void Passenger::setName(string s) {name = s;}
void Passenger::setPay_Pref(string s) {pay_pref = s;}
void Passenger::setHandicapped(bool b) {handicapped = b;}
void Passenger::setPets(bool b) {pets = b;}
void Passenger::setRating(float f) {rating = f;}

int Passenger::getID() {return ID;}
string Passenger::getName() {return name;}
string Passenger::getPay_Pref() {return pay_pref;}
bool Passenger::getHandicapped() {return handicapped;}
bool Passenger::getPets() {return pets;}
float Passenger::getRating() {return rating;}

void Passenger::editPassenger()
{ //edits a single passenger
char uc;	

	do 
	{
		this->printPassenger();
		cout << endl;
		cout << "****************" << endl;
		cout << "What would you like to edit?" << endl;
		cout << "n - name" << endl;
		cout << "m - Paymeny Preference" << endl;
		cout << "h - handicapped status" << endl;
		cout << "p - pet status" << endl;
		cout << "r - rating" << endl;
		cout << "q - quit editing" << endl;
		
		cin >> uc;

		string tempstring;
		char muc;
		char huc;
		char puc;
		float tempfloat;

		cout << endl;

		switch (uc)
		{
			case 'n':
				cout << "Please enter the passengers new name: ";
				cin.ignore();
				getline(cin, tempstring);
				name = tempstring;
				break;
			case 'm':
				do
				{
					cout << "****************" << endl;
					cout << "What is the passengers preferred payment method?" << endl;
					cout << "c - credit" << endl;
					cout << "d - debit" << endl;
					cout << "m - cash" << endl;
					cout << "x - other (will need to enter)" << endl;
					cin >> muc;
				} while (muc != 'c' & muc != 'd' & muc != 'm' & muc != 'x');
	
				if (muc == 'c')
				{pay_pref = "credit";}
				else if (muc == 'd')
				{pay_pref = "debit";}
				else if (muc == 'm')
				{pay_pref = "cash";}
				else
				{
					cout << "Please enter other payment method";
					cin.ignore();
					getline(cin, tempstring);
					pay_pref = tempstring;
				}
				break;
			case 'h':
				do
				{
					cout << "****************" << endl;
					cout << "Is the passenger handicapped?" << endl;
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
					cout << "Does the passenger have pets?" << endl;
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
			case 'q':
				break;
			default:
				cout << "Incorrect input, please try again." << endl;
				break;
		}
	} while (uc != 'q'); //loops until user is done editing
}

void Passenger::printPassenger()
{ //prints a single passenger
	cout << endl << "*****" << endl;
	cout << "Passenger ID: " << ID << endl;
	cout << "Passenger Name: " << name << endl;
	cout << "Preferred Payment: " << pay_pref << endl;

	cout << "Handicapped: ";
	if (handicapped == 0) {cout << "NO" << endl;}
	else if (handicapped ==1) {cout << "YES" << endl;}

	cout << "Pets: ";
	if (pets == 0) {cout << "NO" << endl;}
	else if (pets ==1) {cout << "YES" << endl;}

	cout << "Passenger Rating: " << rating << endl;
}
void Passenger::operator = ( const Passenger &P )
{ //overloads =
	ID = P.ID;
	name = P.name;
	pay_pref = P.pay_pref;
	handicapped = P.handicapped;
	pets = P.pets;
	rating = P.rating;
}
