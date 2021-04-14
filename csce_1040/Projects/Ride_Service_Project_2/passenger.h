//passenger.h
/*
Name: Alexander Kahanek (ark0174)
Teacher: David Keathly
Date: 3/22/2020
*/

#include <iostream>
using namespace std;

class Passenger
{
	private:
		int ID;
		string name;
		string pay_pref;
		bool handicapped; //0 = no, 1 = yes
		bool pets; //0 = no, 1 = yes
		float rating; //[0-10] 

	public:
		Passenger();

		void setID(int i);
		void setName(string s);
		void setPay_Pref(string s);
		void setHandicapped(bool b);
		void setPets(bool b);
		void setRating(float f);

		int getID();
		string getName();
		string getPay_Pref();
		bool getHandicapped();
		bool getPets();
		float getRating();

		void editPassenger();
		void printPassenger();
		void operator = (const Passenger &P );
		
};
