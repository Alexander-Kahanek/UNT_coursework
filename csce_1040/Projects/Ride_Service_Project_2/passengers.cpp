//passengers.cpp
/*
Name: Alexander Kahanek (ark0174)
Teacher: David Keathly
Date: 3/22/2020
*/

#include <iostream>
#include "passengers.h"
using namespace std;

Passengers::Passengers() {total_passengers =0; cnt=1;}

void Passengers::setTotal(int t) {total_passengers = t;}

int Passengers::getTotal() {return total_passengers;}

void Passengers::addCnt() {++cnt;}

void Passengers::setCnt(int i) {cnt = i;}

int Passengers::getCnt() {return cnt;}

void Passengers::setVector(vector<Passenger> vp) {vec_passengers = vp;}

vector<Passenger> Passengers::getVector() {return vec_passengers;}

void Passengers::set_a_Passenger(Passenger p)
{vec_passengers.push_back(p); total_passengers += 1;}

Passenger Passengers::get_a_Passenger(int id)
{ //pulls a single passenger out of a class, based on id of passenger
	for (int i =0; i < vec_passengers.size(); ++i)
	{
		if (vec_passengers[i].getID() == id)
		{
			return vec_passengers[i];
		}
	}
}

bool Passengers::get_party_h()
{ //finds total party handicapped status
	for (int i =0; i < vec_passengers.size(); ++i)
	{
		if (vec_passengers[i].getHandicapped() ==1)
		{return 1;}
	}
	return 0;
}

bool Passengers::get_party_p()
{ //returns total party pets status
	for (int i =0; i < vec_passengers.size(); ++i)
	{
		if (vec_passengers[i].getPets() ==1)
		{return 1;}
	}
	return 0;
}


void Passengers::editPassenger(int id)
{ //edits a single passenger
	for (int i =0; i < vec_passengers.size(); ++i)
	{
		if (vec_passengers[i].getID() == id)
		{
			vec_passengers[i].editPassenger();
		}
	}
}


void Passengers::addPassenger()
{ //adds a passenger
	Passenger p; //current passenger being added

	string tempstr;
	int tempint;
	bool tempbool;
	float tempfloat;
	char uc;

	p.setID(cnt);
	addCnt();
	
	cin.ignore();

	cout << endl << "Please enter passengers name: ";
	getline(cin, tempstr); p.setName(tempstr);

	do
	{
		cout << "****************" << endl;
		cout << "Is the passenger handicapped?" << endl;
		cout << "y - yes" << endl;
		cout << "n - no" << endl;
		cin >> uc;
	} while (uc != 'y' & uc != 'n');

	if (uc == 'y')
	{ p.setHandicapped(1); }
	else
	{ p.setHandicapped(0); }

	do
	{
		cout << "****************" << endl;
		cout << "Does the passenger have pets?" << endl;
		cout << "y - yes" << endl;
		cout << "n - no" << endl;
		cin >> uc;
	} while (uc != 'y' & uc != 'n'); 

	if (uc == 'y')
	{ p.setPets(1); }
	else
	{ p.setPets(0); }

	do
	{
		cout << "Please enter passengers rating on a scale of 0 - 10: ";
		cin >> tempfloat;
	}while(tempfloat <0 & tempfloat >10);
	p.setRating(tempfloat);


	do
	{
		cout << "****************" << endl;
		cout << "What is the passengers preferred payment method?" << endl;
		cout << "c - credit" << endl;
		cout << "d - debit" << endl;
		cout << "m - cash" << endl;
		cout << "x - other (will need to enter)" << endl;
		cin >> uc;
	} while (uc != 'c' & uc != 'd' & uc != 'm' & uc != 'x');

	if (uc == 'c')
	{p.setPay_Pref("credit");}
	else if (uc == 'd')
	{p.setPay_Pref("debit");}
	else if (uc == 'm')
	{p.setPay_Pref("cash");}
	else
	{
		cout << "Please enter other payment method: ";
		cin.ignore();
		getline(cin, tempstr);
		p.setPay_Pref(tempstr);
	}

	vec_passengers.push_back(p);
	total_passengers += 1;

	p.printPassenger();

}
void Passengers::deletePassenger(int id)
{ //deletes a single passenger, with prompt
	for (int i =0; i < vec_passengers.size(); ++i)
	{
		if (vec_passengers[i].getID() == id)
		{
			vec_passengers[i].printPassenger();
			cout << "Here is your Passenger, are you sure you want to delete?" << endl;
			char uc;
			do {
				cout << "(y on n) ";
				cin >> uc;
			}while (uc != 'y' & uc != 'n');

			if (uc == 'y')
			{ vec_passengers.erase(vec_passengers.begin()+i); total_passengers -=1;}
			else
			{ cout << "Going back, Passenger was not deleted." << endl; }

		}
	}

}

int Passengers::findByID(int id)
{ //finds passenger based on id, returns id if found
	do {
		for (int i =0; i < vec_passengers.size(); ++i)
		{
			if (vec_passengers[i].getID() == id)
			{
				return vec_passengers[i].getID();
			}
		}
		cout << endl;
		cout << "Passenger ID could not be found, please enter a new ID number." << endl;
		cout << "Please enter 0 to quit, otherwise the IDs are from 1 to " << cnt-1 << ": ";
		cin >> id;
	} while ( id != 0 );

	return 0;
}

int Passengers::findByName(string n)
{ //finds passenger based on name, returns id if found
	int count=0;
	vector<int> index;

	do {
		count=0;
		cout << endl << "**** We found these Passengers with the name " << n << " ****" << endl;
		for (int i =0; i < vec_passengers.size(); ++i)
		{
			if (vec_passengers[i].getName() == n)
			{
				count +=1;
				cout << count <<" - Passenger Name: " << vec_passengers[i].getName() << ", ID:" << vec_passengers[i].getID();
				cout << ", Payment Preference: " << vec_passengers[i].getPay_Pref() << endl;
				index.push_back(i);
			}
		}

	int uc;
	char cuc;

	if (count == 1)
	{
		do
		{
			cout << endl;
			cout << "****************" << endl;
			cout << "Would you like to use this Passenger?" << endl;
			cout << "y - yes" << endl;
			cout << "n - no" << endl;
			cout << "q - quit" << endl;
			cin >> cuc;
		}while (cuc != 'y' & cuc != 'n' & cuc != 'q');

		if (cuc == 'y')
		{ return vec_passengers[index[0]].getID(); }
		else if (cuc == 'n')
		{}
		else if (cuc == 'q')
		{ return 0; }
	}
	else if (count > 0)
	{
		cout << endl << "Which passenger are you looking for?" << endl;
		do { 
			cout << "Please enter the number for your passenger, or 0 to quit: ";
			cin >> uc; 
		} while (uc < 0 || uc > count);

		if (uc != 0 )
		{
			cout << "Returning ... Passenger Name: " << vec_passengers[index[uc-1]].getName() << ", ID:" << vec_passengers[index[uc-1]].getID();
			cout << ", Payment Preference: " << vec_passengers[index[uc-1]].getPay_Pref() << endl;

			return vec_passengers[index[uc-1]].getID();
		}
	}
	else if (count == 0)
	{
		cout << "**Could not find any passengers by that name**" << endl;
		return 0;
		
		
	}
	
	if (uc == 0 || cuc == 'n')
	{
		cout << "Please enter a new name, or type q to exit: ";
		cin.ignore();
		getline(cin,n);
		if ( n == "") {cout << "There was an error, please try again: ";getline(cin,n);}
		if (n == "q") {return 0;}
	}


	index.clear();
	}while (n != "q");

	return 0;
}

void Passengers::printAllPassengers()
{ //prints all passengers
	int count =0;
	cout << "********************";
	for (int i =0; i < vec_passengers.size(); ++i)
	{vec_passengers[i].printPassenger(); ++count;}

	if (count ==0)//no passengers
	{cout << endl << "***** NO PASSENGERS FOUND *****" << endl;}

}

void Passengers::print_a_Passenger(int id)
{ //prints a single passenger based on id
	for (int i =0; i < vec_passengers.size(); ++i)
	{
		if (vec_passengers[i].getID() == id)
		{vec_passengers[i].printPassenger();}
	}

}
void Passengers::savePassengers()
{

	ofstream fout;
	fout.open("passengers_data.dat");

	fout << total_passengers << " " << cnt << endl;
	for (int i =0; i < vec_passengers.size(); ++i)
	{
		fout << vec_passengers[i].getID() << " "; //int
		fout << vec_passengers[i].getHandicapped() << " "; //bool
		fout << vec_passengers[i].getPets() << " "; //bool
		fout << vec_passengers[i].getRating() << endl; //float
		fout << vec_passengers[i].getName() << endl; //string
		fout << vec_passengers[i].getPay_Pref() << endl; //string
	}

	fout.close();
}

void Passengers::loadPassengers()
{
	total_passengers =0; cnt=1;
	vec_passengers.clear();

	ifstream fin;
	fin.open("passengers_data.dat");

	if (fin.fail())
	{
		cout << "****No Passenger data could be found****" << endl << endl;
		return;
	}

	cout << "****Previous Passenger data loaded****" << endl << endl;

	int tempint;
	bool tempbool;
	string tempstring;
	float tempfloat;

	fin >> tempint;
	total_passengers = tempint;

	fin >> tempint;
	cnt = tempint;

	for (int i =0; i < total_passengers; ++i)
	{
		Passenger p;
		fin >> tempint; p.setID(tempint);
		fin >> tempbool; p.setHandicapped(tempbool);
		fin >> tempbool; p.setPets(tempbool);
		fin >> tempfloat; p.setRating(tempfloat);

		fin.ignore();
		getline(fin,tempstring); p.setName(tempstring);

		getline(fin,tempstring); p.setPay_Pref(tempstring);

		vec_passengers.push_back(p);
	}
	

	fin.close();
}
