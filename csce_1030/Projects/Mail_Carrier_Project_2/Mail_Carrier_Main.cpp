/*
Author:		Alexander Kahanek (alexanderkahanek@my.unt.edu)
Date: 		5 OCT 2019
Instructor: 	Pradhumna Shrestha	
Description:	Program designed for user input shipping prices, based on zipcodes and set rates.
*/

#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;
int main ()
{
	cout << "+----------------------------------------------------------+"<< endl;
	cout << "|             Computer Science and Engineering             |"<< endl;
	cout << "|              CSCE 1030 - Computer Science I              |"<< endl;
	cout << "| Alexander Kahanek  ark0174   alexanderkahanek@my.unt.edu |"<< endl;
	cout << "+----------------------------------------------------------+"<< endl;

	enum {AIR=1, TRUCK=2, COURIER=3, EXIT=4}; //four options
	int userKey; //declare users choice
	bool VALID_ENTRY; //for do-while loop to work
	do 
	{

		
		cout << "+**************** M E N U ***************+"<< endl;
		cout << "| Choose a Service for Package Delivery: |"<< endl;
		cout << "| 1. FastShip Air (EXPEDITED)            |"<< endl;
		cout << "| 2. FastShip Freight Truck (PRIORITY)   |"<< endl;
		cout << "| 3. FastShip Local Courier (STANDARD)   |"<< endl;
		cout << "| 4. Exit                                |"<< endl;
		cout << "+****************************************+"<< endl;

		cout << "Enter shipping service, or exit: "; cin >> userKey; //get users input of service


		float totalCost=0.0; //total cost starts at 0
		bool ZIP_IS_BAD; //for do-while loop on zipcode check
		cout.setf(ios::fixed); //for decimal precision
		cout.setf(ios::showpoint); //for decimal precision
	
		switch (userKey)
		{
			case 1: //choice 1 = Fast Ship Air
				{
				int origZip; //declare original zipcode
				int destZip; //declare destination zipcode
				float packWeight; //declase package weight
				const float AIR_COST = 0.295; //declare shipping type w/ constant
				do
				{

					cout << "Please enter the original Zip-Code: "; cin >> origZip; //recieve user original zip
					if (origZip <0 || origZip > 99999) //if original zip is outside of range
					{
						cout << "Invlaid entry." << endl;
						ZIP_IS_BAD=true; //repeats to ask again
					}
					else
					{
						ZIP_IS_BAD=false; //ends loop to procceed to destination zip
					}
				} while (ZIP_IS_BAD);
				//--------------------------------------------------------------------------
				do
				{

					cout << "Please enter the destination Zip-Code: "; cin >> destZip; //recieve user destination zip
					if (destZip <0 || destZip > 99999) //if destination zip is outside of range
					{
						cout << "Invlaid entry." << endl;
						ZIP_IS_BAD=true; //repeats to ask again
					}
					else
					{
						ZIP_IS_BAD=false; //ends loop to procceed to destination zip
					}
				} while (ZIP_IS_BAD);
				//--------------------------------------------------------------------------
				do
				{
					cout << "Please enter the Package Weight: "; cin >> packWeight; //recieve user package weight
					if (packWeight <0) //package weight cannot be less than 0
					{
						cout << "Invlaid entry." << endl;
						ZIP_IS_BAD=true; // if less than 0, repeat
					}
					else
					{
						ZIP_IS_BAD=false; //ends loop if package weight is within allowed range
					}
				} while (ZIP_IS_BAD);
				//--------------------------------------------------------------------------
				float packDist = fabs((origZip - destZip)/1000.0); //absolute value of difference of zipcodes, divided by 1000
				float totalShipCost = packDist * packWeight * AIR_COST; //formula to calculate total cost
				
				cout.precision(2); //sets decimal to 2, since money
				cout <<"The total cost to ship your package is: " <<  totalShipCost << endl; 
				break;
				}

			//************************************************************************************************************************
			case 2: //choice 2 = Fast Ship Truck
				{
				int origZip; //declare original zipcode
				int destZip; //declare destination zipcode
				float packWeight; //declase package weight
				const float TRUCK_COST = 0.165; //declare shipping type w/ constant
				do
				{

					cout << "Please enter the original Zip-Code: "; cin >> origZip; //recieve user original zip
					if (origZip <0 || origZip > 99999) //if original zip is outside of range
					{
						cout << "Invlaid entry." << endl;
						ZIP_IS_BAD=true; //repeats to ask again
					}
					else
					{
						ZIP_IS_BAD=false; //ends loop to procceed to destination zip
					}
				} while (ZIP_IS_BAD);
				//--------------------------------------------------------------------------
				do
				{

					cout << "Please enter the destination Zip-Code: "; cin >> destZip; //recieve user destination zip
					if (destZip <0 || destZip > 99999) //if destination zip is outside of range
					{
						cout << "Invlaid entry." << endl;
						ZIP_IS_BAD=true; //repeats to ask again
					}
					else
					{
						ZIP_IS_BAD=false; //ends loop to procceed to destination zip
					}
				} while (ZIP_IS_BAD);
				//--------------------------------------------------------------------------
				do
				{
					cout << "Please enter the Package Weight: "; cin >> packWeight; //recieve user package weight
					if (packWeight <0) //package weight cannot be less than 0
					{
						cout << "Invlaid entry." << endl;
						ZIP_IS_BAD=true; // if less than 0, repeat
					}
					else
					{
						ZIP_IS_BAD=false; //ends loop if package weight is within allowed range
					}
				} while (ZIP_IS_BAD);
				//--------------------------------------------------------------------------
				float packDist = fabs((origZip - destZip)/1000.0); //absolute value of difference of zipcodes, divided by 1000
				float totalShipCost = packDist * packWeight * TRUCK_COST; //formula to calculate total cost
				
				cout.precision(2); //sets decimal to 2, since money
				cout <<"The total cost to ship your package is: " <<  totalShipCost << endl; 
				break;
				}

			//************************************************************************************************************************
			case 3: //choice 3 = Fast Ship Courier
				{
				int origZip; //declare original zipcode
				int destZip; //declare destination zipcode
				float packWeight; //declase package weight
				const float COURIER_COST = 0.085; //declare shipping type w/ constant
				do
				{

					cout << "Please enter the original Zip-Code: "; cin >> origZip; //recieve user original zip
					if (origZip <0 || origZip > 99999) //if original zip is outside of range
					{
						cout << "Invlaid entry." << endl;
						ZIP_IS_BAD=true; //repeats to ask again
					}
					else
					{
						ZIP_IS_BAD=false; //ends loop to procceed to destination zip
					}
				} while (ZIP_IS_BAD);
				//--------------------------------------------------------------------------
				do
				{

					cout << "Please enter the destination Zip-Code: "; cin >> destZip; //recieve user destination zip
					if (destZip <0 || destZip > 99999) //if destination zip is outside of range
					{
						cout << "Invlaid entry." << endl;
						ZIP_IS_BAD=true; //repeats to ask again
					}
					else
					{
						ZIP_IS_BAD=false; //ends loop to procceed to destination zip
					}
				} while (ZIP_IS_BAD);
				//--------------------------------------------------------------------------
				do
				{
					cout << "Please enter the Package Weight: "; cin >> packWeight; //recieve user package weight
					if (packWeight <0) //package weight cannot be less than 0
					{
						cout << "Invlaid entry." << endl;
						ZIP_IS_BAD=true; // if less than 0, repeat
					}
					else
					{
						ZIP_IS_BAD=false; //ends loop if package weight is within allowed range
					}
				} while (ZIP_IS_BAD);
				//--------------------------------------------------------------------------
				float packDist = fabs((origZip - destZip)/1000.0); //absolute value of difference of zipcodes, divided by 1000
				float totalShipCost = packDist * packWeight * COURIER_COST; //formula to calculate total cost
				
				cout.precision(2); //sets decimal to 2, since money
				cout <<"The total cost to ship your package is: " <<  totalShipCost << endl; 
				break;
				}
			//************************************************************************************************************************
			case 4: //choice 4 = end of program
				{
				cout << "Thank you for using Fast-Ship Services!" << endl; //be a good human
				return 0; //ends program when chosen to exit
				break;
				}

		}

		if (userKey >=1 && userKey <=4) //checks user entry for valid [1,4]
		{
			VALID_ENTRY = true; //allows loop to run
		}
		else
		{
			cout << "Invalid entry, please choose 1-4." << endl; //message for invalid entry from user
		}	
	} while (VALID_ENTRY);	//loop will always run, user must exit via menu

		
	




	return 0;
}