//drivers.cpp
/*
Name: Alexander Kahanek (ark0174)
Teacher: David Keathly
Date: 3/22/2020
*/

#include <iostream>
#include "drivers.h"
using namespace std;


Drivers::Drivers() {total_drivers =0; cnt=1;}

void Drivers::setTotal(int t) {total_drivers = t;}

void Drivers::setCnt(int i) {cnt = i;}

int Drivers::getCnt() {return cnt;}

int Drivers::getTotal() {return total_drivers;}

void Drivers::addCnt() {++cnt;} //adds value to id, when new driver is made

void Drivers::editDriver(int id)
{ //calls function for editing a driver based on id
	for (int i =0; i < vec_drivers.size(); ++i)
	{
		if (vec_drivers[i].getID() == id)
		{
			vec_drivers[i].editDriver();
		}
	}
}

void Drivers::setVector(vector<Driver> vd) {vec_drivers = vd;}
vector<Driver> Drivers::getVector() {return vec_drivers;}

void Drivers::check(bool h, bool p, float r)
{ //function check for add ride, based on handicapped, pets, and rating
	for (int i =0; i < vec_drivers.size(); ++i)
	{
		if (vec_drivers[i].getAvailable() == 0)
		{vec_drivers.erase(vec_drivers.begin()+i); total_drivers -= 1;}

		if (h == 1)
		{
			if (vec_drivers[i].getHandicapped() == 0)
			{vec_drivers.erase(vec_drivers.begin()+i); total_drivers -= 1;}
		}
		
		if (p == 1)
		{
			if (vec_drivers[i].getPets() == 0)
			{vec_drivers.erase(vec_drivers.begin()+i); total_drivers -= 1;}
		}

		if (vec_drivers[i].getRating() < r)
		{vec_drivers.erase(vec_drivers.begin()+i); total_drivers -= 1;}

		//check times
	}
}

int Drivers::choose()
{ //lets user choosee from the drivers on called class
	int count=0;
	vector<int> index;
	char exit;

	do {
		count=0;
		cout << endl << "**** We found these Drivers that fit your party ****" << endl;
		for (int i =0; i < vec_drivers.size(); ++i)
		{	
			count +=1;
			cout << count <<" - Drivers Name: " << vec_drivers[i].getName() << ", ID:" << vec_drivers[i].getID();
			cout << ", Vehicle: " << vec_drivers[i].getVehicle() << endl;
			index.push_back(i);
		}

	int uc;
	char cuc;

	if (count == 1)
	{
		do
		{
			cout << endl;
			cout << "****************" << endl;
			cout << "Would you like to use this Driver?" << endl;
			cout << "y - yes" << endl;
			cout << "q - quit" << endl;
			cin >> cuc;
		}while (cuc != 'y' & cuc != 'n' & cuc != 'q');

		if (cuc == 'y')
		{ return vec_drivers[index[0]].getID(); }
		else if (cuc == 'q')
		{ exit = 'q'; }
	}
	else if (count > 0)
	{
		cout << endl << "Which driver are you looking for?" << endl;
		do { 
			cout << "Please enter the number for your driver, or 0 to quit: ";
			cin >> uc; 
		} while (uc < 0 || uc > count);

		if (uc != 0 )
		{
			cout << endl << "****************" << endl;
			cout << "Using ... Drivers Name: " << vec_drivers[index[uc-1]].getName() << ", ID:" << vec_drivers[index[uc-1]].getID();
			cout << ", Vehicle: " << vec_drivers[index[uc-1]].getVehicle() << endl;
			cout << "****************" << endl;

			return vec_drivers[index[uc-1]].getID();
		}
	}
	else if (count == 0)
	{
		cout << "Could not find any drivers that fit your parties needs, please try again." << endl;
		exit = 'q';
	}
	
	index.clear();
	}while (exit != 'q');

	return 0;


}

void Drivers::delete_for_time(int id)
{ //deletes drivers based on id, without prompt for asking
	for (int i =0; i < vec_drivers.size(); ++i)
	{
		if (vec_drivers[i].getID() == id)
		{
			vec_drivers.erase(vec_drivers.begin()+i); total_drivers -= 1;
		}	
	}
}

void Drivers::addDriver()
{ //adds a driver
	Driver d; //current driver being added
	string tempstr;
	int tempint;
	bool tempbool;
	float tempfloat;
	char uc;

		

	d.setID(cnt);
	addCnt();
	
	cin.ignore();

	cout << endl << "Please enter drivers name: ";
	getline(cin, tempstr); d.setName(tempstr);

	cout << "Please enter drivers vehicle: ";
	getline(cin, tempstr); d.setVehicle(tempstr);

	cout << "Please enter drivers vehicle capacity: ";
	cin >> tempint; d.setVeh_Cap(tempint);

	do
	{
		cout << "****************" << endl;
		cout << "Is the driver able to take handicapped passengers?" << endl;
		cout << "y - yes" << endl;
		cout << "n - no" << endl;
		cin >> uc;
	} while (uc != 'y' & uc != 'n');

	if (uc == 'y')
	{ d.setHandicapped(1); }
	else
	{ d.setHandicapped(0); }

	do
	{
		cout << "****************" << endl;
		cout << "Is the driver able to take pets?" << endl;
		cout << "y - yes" << endl;
		cout << "n - no" << endl;
		cin >> uc;
	} while (uc != 'y' & uc != 'n'); 

	if (uc == 'y')
	{ d.setPets(1); }
	else
	{ d.setPets(0); }

	do
	{
		cout << "Please enter drivers rating on a scale of 0 - 10: ";
		cin >> tempfloat;
	}while(tempfloat <0 & tempfloat >10);
	d.setRating(tempfloat);

	//AVAILABLE if driver has weekday schedule

	cin.ignore();

	cout << "Please enter any additional notes: ";
	getline(cin,tempstr); d.setNotes(tempstr);

	d.printDriver();	

	vec_drivers.push_back(d);
	total_drivers += 1;

}
void Drivers::deleteDriver(int id)
{ //deletes a driver, given prompt for user
	for (int i =0; i < vec_drivers.size(); ++i)
	{
		if (vec_drivers[i].getID() == id)
		{
			vec_drivers[i].printDriver();
			cout << endl << "Here is your Driver, are you sure you want to delete?" << endl;
			char uc;
			do {
				cout << "(y on n) ";
				cin >> uc;
			}while (uc != 'y' & uc != 'n');

			if (uc == 'y')
			{ vec_drivers.erase(vec_drivers.begin()+i); total_drivers -= 1;}
			else
			{ cout << "Going back, Driver was not deleted." << endl; }
		}	
	}

}

int Drivers::findByID(int id)
{ //finds driver based on id, returns id if found
	do {
		for (int i =0; i < vec_drivers.size(); ++i)
		{
			if (vec_drivers[i].getID() == id)
			{
				return vec_drivers[i].getID();
			}
		}
		cout << endl;
		cout << "Driver ID could not be found, please enter a new ID number." << endl;
		cout << "Please enter 0 to quit, otherwise the IDs are from 1 to " << cnt-1 << ": ";
		cin >> id;
	} while ( id != 0 );
}

int Drivers::findByName(string n)
{ //finds driver based on name, returns id
	int count=0;
	vector<int> index;

	do {
		count=0;
		cout << endl << "**** We found these Drivers with the name " << n << " ****" << endl;
		for (int i =0; i < vec_drivers.size(); ++i)
		{
			if (vec_drivers[i].getName() == n)
			{
				count +=1;
				cout << count <<" - Drivers Name: " << vec_drivers[i].getName() << ", ID:" << vec_drivers[i].getID();
				cout << ", Vehicle: " << vec_drivers[i].getVehicle() << endl;
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
			cout << "Would you like to use this Driver?" << endl;
			cout << "y - yes" << endl;
			cout << "n - no" << endl;
			cout << "q - quit" << endl;
			cin >> cuc;
		}while (cuc != 'y' & cuc != 'n' & cuc != 'q');

		if (cuc == 'y')
		{ return vec_drivers[index[0]].getID(); }
		else if (cuc == 'n')
		{}
		else if (cuc == 'q')
		{ return 0; }
	}
	else if (count > 0)
	{
		cout << endl << "Which driver are you looking for?" << endl;
		do { 
			cout << "Please enter the number for your driver, or 0 to quit: ";
			cin >> uc; 
		} while (uc < 0 || uc > count);

		if (uc != 0 )
		{
			cout << "Returning ... Drivers Name: " << vec_drivers[index[uc-1]].getName() << ", ID:" << vec_drivers[index[uc-1]].getID();
			cout << ", Vehicle: " << vec_drivers[index[uc-1]].getVehicle() << endl;

			return vec_drivers[index[uc-1]].getID();
		}
	}
	else if (count == 0)
	{
		cout << "**Could not find any drivers by that name**" << endl;
		return 0;


	}
	
	if (uc == 0 || cuc == 'n')
	{
		cout << endl << "Please enter a new name, or type q to exit: ";
		cin.ignore();
		getline(cin,n);
		if ( n == "") {cin.ignore();cin.ignore();cout << "There was an error, please try again: ";getline(cin,n);}
		if (n == "q") {return 0;}
	}
	index.clear();
	}while (n != "q");

	return 0;
}

void Drivers::printAllDrivers()
{ //prints all drivers
	int count = 0;
	cout << "********************";
	for (int i =0; i < vec_drivers.size(); ++i)
	{vec_drivers[i].printDriver(); ++count;}

	if (count ==0)//no drivers
	{cout << endl << "***** NO DRIVERS FOUND *****" << endl;}

}

void Drivers::print_a_Driver(int id)
{ //prints a single driver based on id
	for (int i =0; i < vec_drivers.size(); ++i)
	{
		if (vec_drivers[i].getID() == id)
		{vec_drivers[i].printDriver();}
	}

}

void Drivers::saveDrivers()
{ //saves drivers to file

	ofstream fout;
	fout.open("drivers_data.dat");

	fout << total_drivers << " " << cnt << endl;
	for (int i =0; i < vec_drivers.size(); ++i)
	{
		fout << vec_drivers[i].getID() << " "; //int
		fout << vec_drivers[i].getVeh_Cap() << " ";
		fout << vec_drivers[i].getHandicapped() << " "; //bool
		fout << vec_drivers[i].getPets() << " "; //bool
		fout << vec_drivers[i].getRating() << " "; //float
		fout << vec_drivers[i].getAvailable() << endl; //bool
		fout << vec_drivers[i].getName() << endl; //string
		fout << vec_drivers[i].getVehicle() << endl; //string
		fout << vec_drivers[i].getNotes() << endl; //string
	}

	fout.close();
}

void Drivers::loadDrivers()
{ //loads driver from file
	total_drivers =0; cnt=1;
	vec_drivers.clear();
	ifstream fin;
	fin.open("drivers_data.dat");

	if (fin.fail())
	{
		cout << "****No Driver data could be found****" << endl << endl;
		return;
	}

	cout << "****Previous Driver data loaded****" << endl << endl;

	int tempint;
	bool tempbool;
	string tempstring;
	float tempfloat;

	fin >> tempint;
	total_drivers = tempint;

	fin >> tempint;
	cnt = tempint;

	for (int i =0; i < total_drivers; ++i)
	{
		Driver d;
		fin >> tempint; d.setID(tempint);
		fin >> tempint; d.setVeh_Cap(tempint);
		fin >> tempbool; d.setHandicapped(tempbool);
		fin >> tempbool; d.setPets(tempbool);
		fin >> tempfloat; d.setRating(tempfloat);
		fin >> tempbool; d.setAvailable(tempbool);

		fin.ignore();
		getline(fin,tempstring); d.setName(tempstring);

		getline(fin,tempstring); d.setVehicle(tempstring);

		getline(fin,tempstring); d.setNotes(tempstring);	

		vec_drivers.push_back(d);
	}
	
	fin.close();
}


