//passengers.h
/*
Name: Alexander Kahanek (ark0174)
Teacher: David Keathly
Date: 3/22/2020
*/

#include <iostream>
#include <vector>
#include <fstream>
#include "passenger.h"
using namespace std;

class Passengers
{
	private:
		int total_passengers;
		vector<Passenger> vec_passengers;
		int cnt;


	public:
		Passengers();

		void setTotal(int t);
		void setCnt(int i);
		void setVector(vector<Passenger> vp);
		void set_a_Passenger(Passenger p);

		int getTotal();
		int getCnt();
		vector<Passenger> getVector();
		Passenger get_a_Passenger(int id);//pulls a single passenger out of a class, based on id of passenger

		bool get_party_h();//finds total party handicapped status
		bool get_party_p(); //returns total party pets status
		void addCnt();
		void editPassenger(int id);//edits a single passenger
		void addPassenger();//adds a passenger
		void deletePassenger(int id);//deletes a single passenger, with prompt
		int findByID(int id);//finds passenger based on id, returns id if found
		int findByName(string n);//finds passenger based on name, returns id if found
		void printAllPassengers();//prints all passengers
		void print_a_Passenger(int id);//prints a single passenger based on id

		void savePassengers();
		void loadPassengers();


};
