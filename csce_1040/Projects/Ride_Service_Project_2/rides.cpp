//rides.cpp
/*
Name: Alexander Kahanek (ark0174)
Teacher: David Keathly
Date: 3/22/2020
*/

#include <iostream>
#include "main.h"

using namespace std; 
Rides::Rides() {total_rides = 0; cnt = 10000000;}

void Rides::setTotal(int t) {total_rides = t;}
void Rides::setCnt(int i) {cnt = i;}

int Rides::getTotal() {return total_rides;}
int Rides::getCnt() {return cnt;}
		
void Rides::addCnt() {++cnt;}

void Rides::update_all_status()
{ //updates all status'
	for (int i =0; i < vec_rides.size(); ++i)
	{
		if (vec_rides[i].getStatus() != 3) //if status is 3, leave it
		{ vec_rides[i].updateStatus(); }
	}

}

void Rides::cancel_ride(int id)
{ //cancels a single ride
	for (int i =0; i < vec_rides.size(); ++i)
	{
		if (vec_rides[i].getID() == id)
		{ vec_rides[i].setStatus(3); vec_rides[i].printRide();}
	}
}

void Rides::addRide(Drivers &D, Passengers &P)
{ //creates a ride and adds it to main rides class
	Drivers available_D; //create and set temp drivers for checking
	available_D.setTotal(D.getTotal());
	available_D.setCnt(D.getCnt());
	available_D.setVector(D.getVector());

	if (available_D.getTotal() == 0) {cout << endl << "*** NO DRIVERS FOR A RIDE ***" << endl; return;}

	Passengers party; //create and set passengers for the ride
	party.setCnt(P.getCnt());

	Ride curr_ride; //current ride being added

	//ask user who wants to add or create new (add to main class when done)
	char uc;
	int party_s=0; //party size
	do
	{
		cout << endl;
		cout << "****************" << endl;
		cout << "You currently have: " << party_s << " passengers in your party." << endl;
		cout << "****************" << endl;
		cout << "Would you like to add current or create passengers?" << endl;
		cout << "f - find a passenger in system" << endl;
		cout << "c - create a new passenger" << endl;
		cout << "q - stop adding passengers" << endl;
		cin >> uc;
		
		int id;
		char euc;
		switch (uc)
		{
			case 'f':
				id = FindPassenger(P);
				if (id != 0 )
				{ 
					P.print_a_Passenger(id);	
					do {
						cout << endl << "Would you like to edit this passenger first? (y or n): ";
						cin >> euc;
					} while ( euc != 'y' & euc != 'n');
					if( euc == 'y')
					{P.editPassenger(id);}
					
					cout << endl << "Adding passenger to your party." << endl;
					party.set_a_Passenger(P.get_a_Passenger(id));
					++party_s;
					curr_ride.setID_P(id);
				}
				break;
			case 'c':
				party.addPassenger();
				id = party.getCnt() -1;
				if (party.getCnt() > P.getCnt())
				{
					P.set_a_Passenger(party.get_a_Passenger(id));
					P.addCnt(); ++party_s; curr_ride.setID_P(id);
				}
				break;
			case 'q':
				break;
			default: 
				cout << "Invalid response, please try again." << endl;
				break;
		}
	}while (uc != 'q');

	//check drivers based on conditions

	curr_ride.setHandicapped(party.get_party_h()); //party needs handicapped accomadations
	curr_ride.setPets(party.get_party_p()); //party need pet accomadations
	//pickup time
	float party_r; //minimum party rating wanted
	do {
		cout << "Please enter the minimum driver rating you are willing to accept: ";
		cin >> party_r;
	} while (party_r < 0 || party_r > 10);
	
	//get pl/dl location
	string pl = "none";
	string dl = "none";

	cout << "Address for pickup (enter q to quit): ";
	cin.ignore();
	getline(cin, pl);
		
	if (pl == "q") {return;}
	curr_ride.setPickup(pl);

	cout << "Address for dropoff: ";
	getline(cin, dl);
	curr_ride.setDropoff(dl);

	int mon;
	int day;
	int hour;
	int min;
		
	cout << "Please enter the time for pickup..." << endl;

	tm user_t = {0}; //placeholder for user entered time
	time_t current_time; //current time placeholder
	time_t epoch_user; //user entered time placeholder for epoch time
	int t_count=0; //counter to fix error
	do
	{
		
		do {cout << "Month (1-12): "; cin >> mon;} while(mon <1 || mon >12);
		do {cout << "Day (1-31): "; cin >> day;} while (day<1 || day>31);
		do {cout << "Hour (0-23): "; cin >> hour;} while (hour <0 || hour >23);
		do {cout << "Min (0-59): "; cin >> min;}while(min <0 || min >59);
		cout << endl;
		current_time =time(0);

		user_t.tm_year = 2020-1900;
		user_t.tm_mon = mon -1;
		user_t.tm_mday = day;

		if (t_count == 0)
		{user_t.tm_hour = hour -1;}
		else
		{user_t.tm_hour = hour;} //no idea why this happens, but error is fixed

		user_t.tm_min = min;
		user_t.tm_sec = 0;
			
		epoch_user = mktime(&user_t);
		if (epoch_user < current_time) {cout << "Please enter a time for the future." << endl;}
		++t_count;
	} while (epoch_user < current_time); //goes until user time is past current time

	curr_ride.setPU_Time(epoch_user);
	
	//get ETA for do_time
	int eta;
	do
	{
		cout << "Please enter the estimated time for your ride (in minutes): ";
		cin >> eta;
	}while (eta < 0); //eta must be positive
	time_t user_do_t = epoch_user + (eta * 60);
	curr_ride.setDO_Time(user_do_t);

	//update status
	curr_ride.updateStatus();

	//delete drivers with active rides during time
	for (int i=0; i < vec_rides.size(); ++i)
	{
		if (vec_rides[i].getDO_Time() >= current_time)
		{
			//ride is in future
			if (epoch_user > vec_rides[i].getPU_Time() )
			{
				//our current pu time is after our rides pickup time
				if (epoch_user > vec_rides[i].getDO_Time())
				{
					//our current pickup time is after our rides dropoff time
					//keep driver
				}
				else
				{
					//our current pickup time is same as or before this rides dropoff time
					//delete driver
					available_D.delete_for_time(vec_rides[i].getID_D());
				}
			}
			else
			{
				//our current pu time is before our rides pickup
				if (user_do_t < vec_rides[i].getPU_Time())
				{
					//our current do time is before our rides pickup time
					//keep driver
				}
				else
				{
					//our current do time is the same or after our rides pickup time
					//delete driver
					available_D.delete_for_time(vec_rides[i].getID_D());
				}
			}
		}
		else
		{
			//ride is in past, do nothing
		}
		
	}
	available_D.check(curr_ride.getHandicapped(), curr_ride.getPets(), party_r);
	if (available_D.getTotal() == 0) {cout << endl << "*** NO DRIVERS AVAILABLE FOR THIS RIDE ***" << endl; return;}
	curr_ride.setID_D(available_D.choose());

	//get rating
	float tempfloat;
	do
	{
		cout << "Please enter the rides rating on a scale of 0 - 10: ";
		cin >> tempfloat;
	}while(tempfloat <0 || tempfloat >10);

	curr_ride.setRating(tempfloat);
	curr_ride.setID(cnt); ++cnt;

	vec_rides.push_back(curr_ride); ++total_rides;	

	curr_ride.printRide();	
}

void Rides::deleteRide(int id)
{ //deletes a specific ride
	for (int i =0; i < vec_rides.size(); ++i)
	{
		if (vec_rides[i].getID() == id)
		{
			vec_rides[i].printRide();
			cout << "Here is your Ride, are you sure you want to delete?" << endl;
			char uc;
			do {
				cout << "(y on n) ";
				cin >> uc;
			}while (uc != 'y' & uc != 'n');

			if (uc == 'y')
			{ vec_rides.erase(vec_rides.begin()+i); total_rides -= 1; }
			else
			{ cout << "Going back, Ride was not deleted." << endl; }

		}
	}

}

void Rides::delete_2_3(int id)
{ //deletes all rides with status 2 or 3
	int cnt_2=0;
	int cnt_3=0;
	vector<int> index;
	if (id == 0)
	{
		for (int i =0; i < vec_rides.size(); ++i)
		{
			if (vec_rides[i].getStatus() == 2)
			{ index.push_back(vec_rides[i].getID()); ++cnt_2; }
			else if (vec_rides[i].getStatus() == 3)
			{ index.push_back(vec_rides[i].getID()); ++cnt_3; }
		}
	
		for (int i=0; i<index.size(); ++i)
		{
			this->delete_2_3(index[i]);
		}
		cout << endl << "***** Deleted " << cnt_2 << " completed rides *****" << endl;
		cout << "***** Deleted " << cnt_3 << " canceled rides *****" << endl;	
	}

	if (id != 0)
	{	
		for (int i =0; i < vec_rides.size(); ++i)
		{
			if (vec_rides[i].getID() == id)
			{
				vec_rides.erase(vec_rides.begin()+i); total_rides -= 1;
			}
		}
	}
}

void Rides::editRide(int id)
{ //edits a ride based on id
	for (int i =0; i < vec_rides.size(); ++i)
	{
		if (vec_rides[i].getID() == id)
		{
			vec_rides[i].editRide();
		}
	}
}

int Rides::findByPassenger(Passengers &P)
{ //finds a ride based on passenger
	int ID=0;
	do
	{

		
		ID = FindPassenger(P);
		if (ID == 0) {return 0;}
		
		vector<int> index;

		for (int i =0; i < vec_rides.size(); ++i)
		{
			vector<int> pass_vec = vec_rides[i].getID_P();
			for (int k=0; k<pass_vec.size(); ++k)
			{
				if (pass_vec[k] == ID)
				{
					index.push_back(i);
				}
			}
		}

		int count = 0;
		cout << endl << "**** We found these Rides that have your passenger ****" << endl;
		for (int i =0; i < index.size(); ++i)
		{
			++count;
			time_t temp = vec_rides[index[i]].getPU_Time();
			cout << count <<" - Ride ID: " << vec_rides[index[i]].getID() << ", Pickup Location: ";
			cout << vec_rides[index[i]].getPickup() << " at " << ctime(&temp) << endl;
		}

		int uc;
		char cuc;

		if (count == 1)
		{
			do
			{
				cout << endl;
				cout << "****************" << endl;
				cout << "Would you like to use this Ride?" << endl;
				cout << "y - yes" << endl;
				cout << "n - no" << endl;
				cout << "q - quit" << endl;
				cin >> cuc;
			}while (cuc != 'y' & cuc != 'n' & cuc != 'q');

			if (cuc == 'y')
			{ cout << "index: "<< index[0] << endl; return vec_rides[index[0]].getID(); }
			else if (cuc == 'n')
			{}
			else if (cuc == 'q')
			{ return 0; }
		}
		else if (count > 0)
		{
			cout << endl << "Which ride are you looking for?" << endl;
			do { 
				cout << "Please enter the number for your ride, or 0 to quit: ";
				cin >> uc; 
			} while (uc < 0 || uc > count);
	
			if (uc != 0 )
			{
				time_t temp = vec_rides[index[uc - 1]].getPU_Time();
				cout << "Returning ... Ride ID: " << vec_rides[index[uc -1]].getID() << ", Pickup Location: ";
				cout << vec_rides[index[uc -1]].getPickup() << " at " << ctime(&temp) << endl;

				return vec_rides[index[uc-1]].getID();
			}
		}
		else if (count == 0)
		{
			cout << "**Could not find any rides with the passenger**" << endl;
			return 0;
		}

		index.clear();


	}while (ID == 0);
	return 0;

}

int Rides::findByID(int id)
{ //finds a ride based on id
	do {
		for (int i =0; i < vec_rides.size(); ++i)
		{
			if (vec_rides[i].getID() == id)
			{
				return vec_rides[i].getID();
			}
		}
		cout << endl;
		cout << "Ride ID could not be found, please enter a new ID number." << endl;
		cout << "Please enter 0 to quit, otherwise the IDs are from 10000000 to " << cnt-1 << ": ";
		cin >> id;
	} while ( id != 0 );

}

int Rides::findByDriver(Drivers &D)
{ //finds a ride based on driver
	int ID;
	do
	{

		
		ID = FindDriver(D);
		if (ID == 0) {return 0;}
		vector<int> index;

		for (int i =0; i < vec_rides.size(); ++i)
		{
			if (vec_rides[i].getID_D() == ID)
			{
				index.push_back(i);
			}
		}

		int count = 0;
		cout << endl << "**** We found these Rides that have your driver ****" << endl;
		for (int i =0; i < index.size(); ++i)
		{
			++count;
			time_t temp = vec_rides[index[i]].getPU_Time();
			cout << count <<" - Ride ID: " << vec_rides[index[i]].getID() << ", Pickup Location: ";
			cout << vec_rides[index[i]].getPickup() << " at " << ctime(&temp) << endl;
		}

		int uc;
		char cuc;

		if (count == 1)
		{
			do
			{
				cout << endl;
				cout << "****************" << endl;
				cout << "Would you like to use this Ride?" << endl;
				cout << "y - yes" << endl;
				cout << "n - no" << endl;
				cout << "q - quit" << endl;
				cin >> cuc;
			}while (cuc != 'y' & cuc != 'n' & cuc != 'q');

			if (cuc == 'y')
			{ cout << "index: "<< index[0] << endl; return vec_rides[index[0]].getID(); }
			else if (cuc == 'n')
			{}
			else if (cuc == 'q')
			{ return 0; }
		}
		else if (count > 0)
		{
			cout << endl << "Which ride are you looking for?" << endl;
			do { 
				cout << "Please enter the number for your ride, or 0 to quit: ";
				cin >> uc; 
			} while (uc < 0 || uc > count);
	
			if (uc != 0 )
			{
				time_t temp = vec_rides[index[uc - 1]].getPU_Time();
				cout << "Returning ... Ride ID: " << vec_rides[index[uc -1]].getID() << ", Pickup Location: ";
				cout << vec_rides[index[uc -1]].getPickup() << " at " << ctime(&temp) << endl;

				return vec_rides[index[uc-1]].getID();
			}
		}
		else if (count == 0)
		{
			cout << "**Could not find any rides with that driver**" << endl;
			return 0;		
		}


		index.clear();
	}while (ID == 0);
	return 0;
}

void Rides::print_by_status()
{ //prints by status, extension of menu
	char uc;
	do
	{
		cout << endl;
		cout << "*****************************************" << endl;
		cout << "What status would you like to search for?" << endl;
		cout << "n - rides that have not started" << endl;
		cout << "a - rides that are currently active" << endl;
		cout << "c - rides that are complete" << endl;
		cout << "x - rides that have been cancelled" << endl;
		cout << "q - quit" << endl;
		cin >> uc;
	}while (uc != 'n' & uc != 'a' & uc != 'c' & uc != 'x' & uc != 'q');

	int user_status;

	if (uc == 'n') {user_status =0;}
	else if (uc == 'a') {user_status=1;}
	else if (uc == 'c') {user_status=2;}
	else if (uc == 'x') {user_status=3;}
	else if (uc == 'q') {return;}

	int count=0;
	cout << endl << "***** Here are all your rides for the requested status *****";
	for (int i=0; i<vec_rides.size(); ++i)
	{
		if (vec_rides[i].getStatus() == user_status)
		{
			vec_rides[i].printRide();
			++count;
		}
	}
	
	if (count == 0) {cout << endl << "** Found no rides with that status **" << endl;}
}

void Rides::print_for_passenger(int id)
{ //prints all rides for passenger, based on id of passenger
	cout << endl << "***** Here are all your rides for the requested passenger *****";
	for (int i =0; i < vec_rides.size(); ++i)
	{
		vector<int> p_id;
		bool tb=0;
		p_id = vec_rides[i].getID_P();
		for (int n=0; n < p_id.size(); ++n)
		{
			if ( p_id[n] == id)
			{ tb = 1; }
		}
		if (tb == 1) {vec_rides[i].printRide();}		
	}

}

void Rides::print_for_driver(int id)
{ //prints all rides for driver, based on id of driver
	cout << endl << "***** Here are all your rides for the requested driver *****";
	for (int i =0; i < vec_rides.size(); ++i)
	{
		if (vec_rides[i].getID_D() == id)
		{
			vec_rides[i].printRide();
		}
	}
}

void Rides::printAllRides()
{ //prints all rides
	int count=0;
	cout << "********************";
	for (int i =0; i < vec_rides.size(); ++i)
	{vec_rides[i].printRide(); ++count;}
	
	if (count ==0)//no rides
	{cout << endl << "***** NO RIDES FOUND *****" << endl;}
}

void Rides::print_a_Ride(int id)
{ //prints a ride based off ride id
	for (int i =0; i < vec_rides.size(); ++i)
	{
		if (vec_rides[i].getID() == id)
		{vec_rides[i].printRide();}
	}
}

void Rides::saveRides()
{ //saves ride class
	ofstream fout;
	fout.open("rides_data.dat");

	fout << total_rides << " " << cnt << endl;
	for (int i =0; i < vec_rides.size(); ++i)
	{
		vector<int> temp;

		fout << vec_rides[i].getID() << " ";
		fout << vec_rides[i].getPU_Time() << " ";
		fout << vec_rides[i].getDO_Time() << " ";
		fout << vec_rides[i].getPets() << " ";
		fout << vec_rides[i].getHandicapped() << " ";
		fout << vec_rides[i].getStatus() << " ";
		fout << vec_rides[i].getRating() << " ";
		fout << vec_rides[i].getID_D() << endl;
		

		temp = vec_rides[i].getID_P();
		fout << temp.size();
		for (int i =0; i < temp.size(); ++i)
		{
			fout << " " << temp[i];
		}
		fout << endl;
		fout << vec_rides[i].getPickup() << endl;
		fout << vec_rides[i].getDropoff() << endl;
	}

	fout.close();

}
void Rides::loadRides()
{ //loads ride class
	total_rides = 0; cnt = 10000000;
	vec_rides.clear();
	ifstream fin;
	fin.open("rides_data.dat");

	if (fin.fail())
	{
		cout << "****No Ride data could be found****" << endl << endl;
		return;
	}

	int tempint;
	int size;
	bool tempbool;
	float tempfloat;
	string tempstring;


	fin >> total_rides >> cnt;
	for (int i =0; i < total_rides; ++i)
	{
		Ride r;

		fin >> tempint; r.setID(tempint);
		fin >> tempint; r.setPU_Time(tempint);
		fin >> tempint; r.setDO_Time(tempint);
		fin >> tempbool; r.setPets(tempbool);
		fin >> tempbool; r.setHandicapped(tempbool);
		fin >> tempint; r.setStatus(tempint);
		fin >> tempfloat; r.setRating(tempfloat);
		fin >> tempint; r.setID_D(tempint);

		fin >> size; //size of party
		for (int n=0; n<size; ++n)
		{
			fin >> tempint; r.setID_P(tempint);
		}

		fin.ignore();
		getline(fin,tempstring); r.setPickup(tempstring);
		getline(fin,tempstring); r.setDropoff(tempstring);
		
		vec_rides.push_back(r);

	}

	fin.close();
	cout << "****Previous Ride data loaded****" << endl << endl;

}
