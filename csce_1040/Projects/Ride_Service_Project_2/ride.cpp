//ride.cpp
/*
Name: Alexander Kahanek (ark0174)
Teacher: David Keathly
Date: 3/22/2020
*/

#include <iostream>
#include "ride.h"
using namespace std;

Ride::Ride()
{
	ID = 10000000;
	pickup = "none";
	dropoff = "none";
	pu_time = time(NULL);
	do_time = time(NULL);
	pets = 0;
	handicapped = 0;
	status = 0;
	rating = 0.0;
	id_d = 0;
}
void Ride::setID(int i) {ID = i;}
void Ride::setPickup(string s) {pickup = s;}
void Ride::setDropoff(string s) {dropoff = s;}
void Ride::setPU_Time(time_t pu) {pu_time = pu;}
void Ride::setDO_Time(time_t dr) {do_time = dr;}
void Ride::setPets(bool b) {pets = b;}
void Ride::setHandicapped(bool b) {handicapped = b;}
void Ride::setStatus(int i) {status = i;}
void Ride::setRating(float f) {rating = f;}
void Ride::setID_P(int i) {id_p.push_back(i);}
void Ride::setID_D(int i) {id_d = i;}

int Ride::getID() {return ID;}
string Ride::getPickup() {return pickup;}
string Ride::getDropoff() {return dropoff;}
time_t Ride::getPU_Time() {return pu_time;}
time_t Ride::getDO_Time() {return do_time;}
int Ride::getSize() {return id_p.size();}
bool Ride::getPets() {return pets;}
bool Ride::getHandicapped() {return handicapped;}
int Ride::getStatus() {return status;}
float Ride::getRating() {return rating;}
int Ride::getID_D() {return id_d;}
vector<int> Ride::getID_P() {return id_p;}

void Ride::editRide()
{ //edits a ride
	char uc;	

	do 
	{
		this->printRide();
		cout << endl;
		cout << "****************" << endl;
		cout << "What would you like to edit?" << endl;
		cout << "a - pickup or dropoff addresses (cannot change times)" << endl;
		cout << "r - rating" << endl;
		cout << "q - quit editing" << endl;
				
		cin >> uc;

		string tempstring;
		char auc;
		float tempfloat;

		switch (uc)
		{
			case 'a':
				do
				{
					cout << endl;
					cout << "****************" << endl;
					cout << "what would you like to edit?" << endl;
					cout << "p - pickup address" << endl;
					cout << "d - dropoff address" << endl;
					cout << "b - both pickup and dropoff address" << endl;
					cout << "q - go back" << endl;
					cin >> auc;
				} while (auc != 'q' & auc != 'p' & auc != 'd' & auc != 'b');
				switch (auc)
				{
					case 'b':
					case 'p':
						cout << "What is the new pickup address? ";
						cin.ignore();
						getline(cin, tempstring);
						pickup = tempstring;
						if (auc != 'b') {break;}
					case 'd':
						cout << "What is the new dropoff address? ";
						if (auc != 'b') {cin.ignore();}
						getline(cin, tempstring);
						dropoff = tempstring;
						break;
					case 'q':
						break;
				}
				break;
			case 'r':
				do
				{
					cout << "Please enter the rides new rating on a scale of 0 - 10: ";
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

void Ride::updateStatus()
{ //updates status of current ride
	time_t curr_time = time(0);

	if (curr_time > pu_time)
	{
		//pu has happened
		if (curr_time > do_time)
		{
			//do has happened
			status =  2;
			return;
		}
		else
		{
			//do has not happened
			status = 1;
			return;
		}
	}
	else
	{
		//pu hasnt happened
		status = 0;
		return;
	}
}

void Ride::printRide()
{ //prints current ride
	cout <<endl << "*****" << endl;
	cout << "Ride ID: " << ID << endl;
	cout << "Driver ID: " << id_d << endl;
	cout << "Size of party | ID's (only passengers): " << id_p.size() << " |";
	for (int i=0; i<id_p.size(); ++i)
	{cout << " " << id_p[i];}
	cout << endl;

	cout << "Handicapped accomodations: ";
	if (handicapped == 0) {cout << "NO" << endl;}
	else if (handicapped ==1) {cout << "YES" << endl;}

	cout << "Pets included: ";
	if (pets == 0) {cout << "NO" << endl;}
	else if (pets ==1) {cout << "YES" << endl;}

	cout << "Pickup Location: " << pickup << endl;
	cout << "Dropoff Location: " << dropoff << endl;
	cout << "Pickup Time: " << ctime(&pu_time);
	cout << "Dropoff Time: " << ctime(&do_time);

	cout << "Status of ride: ";
	if (status == 0) {cout << "NOT STARTED" << endl;}
	else if (status == 1) {cout << "ACTIVE - IN PROCESS" << endl;}
	else if (status == 2) {cout << "FINISHED" << endl;}
	else if (status == 3) {cout << "CANCELLED" << endl;}

	cout << "Customer rating: " << rating << endl;
}

void Ride::operator = (const Ride &R )
{ //overloads =
	ID = R.ID;
	pickup = R.pickup;
	dropoff = R.dropoff;
	pu_time = R.pu_time;
	do_time = R.do_time;
	handicapped = R.handicapped;
	pets = R.pets;
	status = R.status;
	rating = R.rating;
	id_d = R.id_d;
	id_p = R.id_p;
}

