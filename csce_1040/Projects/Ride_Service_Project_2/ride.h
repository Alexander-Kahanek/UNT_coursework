//ride.h
/*
Name: Alexander Kahanek (ark0174)
Teacher: David Keathly
Date: 3/22/2020
*/

#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

class Ride
{
	private:
		int ID;
		string pickup;
		string dropoff;
		time_t pu_time;
		time_t do_time;
		bool pets;
		bool handicapped;
		int status; //0 - not started, 1 - active, 2 - complete, 3 - cancelled
		float rating;
		int id_d;
		vector<int> id_p;
		

	public:
		Ride();
		void setID(int i);
		void setPickup(string s);
		void setDropoff(string s);
		void setPU_Time(time_t pu);
		void setDO_Time(time_t dr);
		void setPets(bool b);
		void setHandicapped(bool b);
		void setStatus(int i);
		void setRating(float f);
		void setID_P(int i);
		void setID_D(int i);
	
		int getID();
		string getPickup();
		string getDropoff();
		time_t getPU_Time();
		time_t getDO_Time();
		bool getPets();
		bool getHandicapped();
		int getStatus();
		float getRating();
		vector<int> getID_P();
		int getID_D();
		int getSize();

		void updateStatus();
		void printRide();
		void editRide();
		void operator = (const Ride &R );
		

		

};