//driver.h
/*
Name: Alexander Kahanek (ark0174)
Teacher: David Keathly
Date: 3/22/2020
*/

#include <iostream>
using namespace std;

class Driver
{
	private:
		int ID;
		string name;
		string vehicle;
		int veh_cap;
		bool handicapped; //0 = no, 1 = yes
		bool pets;  //0 = no, 1 = yes
		float rating; //[0-10]
		bool available; //1 is available, 0 is not available
		string notes;

	public:
		Driver();

		void setID(int i);
		void setName(string s);
		void setVehicle(string s);
		void setVeh_Cap(int i);
		void setHandicapped(bool b);
		void setPets(bool b);
		void setRating(float f);
		void setAvailable(bool b);
		void setNotes(string s);

		int getID();
		string getName();
		string getVehicle();
		int getVeh_Cap();
		bool getHandicapped();
		bool getPets();
		float getRating();
		bool getAvailable();
		string getNotes();

		void editDriver();
		void printDriver();
		void operator = (const Driver &D );
};
