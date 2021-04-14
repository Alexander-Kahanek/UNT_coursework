//drivers.h
/*
Name: Alexander Kahanek (ark0174)
Teacher: David Keathly
Date: 3/22/2020
*/

#include <iostream>
#include <vector>
#include <fstream>
#include "driver.h"
using namespace std;

class Drivers
{
	private:
		int total_drivers;
		vector<Driver> vec_drivers;
		int cnt;


	public:
		Drivers();

		void setTotal(int t);
		void setCnt(int i);
		void setVector(vector<Driver> vd);
		int getTotal();
		int getCnt();
		vector<Driver> getVector();

		void check(bool h, bool p, float r);//function check for add ride, based on handicapped, pets, and rating
		int choose();//lets user choosee from the drivers on called class
		void addCnt();//adds value to id, when new driver is made
		void addDriver();//adds a driver
		void editDriver(int id);//calls function for editing a driver based on id
		void deleteDriver(int id);//deletes a driver, given prompt for user

		int findByID(int id);//finds driver based on id, returns id if found
		int findByName(string n);//finds driver based on name, returns id
		void printAllDrivers();//prints all drivers
		void print_a_Driver(int id);//prints a single driver based on id

		void delete_for_time(int id); //deletes drivers based on id, without prompt for asking

		void saveDrivers();//saves drivers to file
		void loadDrivers();//loads driver from file


};