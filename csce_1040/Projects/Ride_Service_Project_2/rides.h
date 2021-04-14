//rides.h
/*
Name: Alexander Kahanek (ark0174)
Teacher: David Keathly
Date: 3/22/2020
*/

#include <iostream>
#include "ride.h"
#include "drivers.h"
#include "passengers.h"
using namespace std;

class Rides
{
	private:
		int total_rides;
		int cnt;
		vector<Ride> vec_rides;


	public:
		Rides();

		void setTotal(int t);
		void setCnt(int i);

		int getTotal();
		int getCnt();
		
		void addCnt();//adds value to id cnt tracker
		void addRide(Drivers &D, Passengers &P);//creates a ride and adds it to main rides class
		void deleteRide(int id);//deletes a specific ride
		void editRide(int id);//edits a ride based on id

		int findByPassenger(Passengers &P);//finds a ride based on passenger
		int findByID(int id);//finds a ride based on id
		int findByDriver(Drivers &D); //finds a ride based on driver

		void print_by_status();//prints by status, extension of menu
		void printAllRides();
		void print_a_Ride(int id);
		void print_for_passenger(int id);//prints all rides for passenger, based on id of passenger
		void print_for_driver(int id);//prints all rides for driver, based on id of driver

		void delete_2_3(int id);//deletes all rides with status 2 or 3
		void cancel_ride(int id);//cancels a single ride
		void update_all_status();//updates all status'
		void saveRides();
		void loadRides();


};