/*
Name: Alexander Kahanek (ark0174)
Teacher: David Keathly
Date: 3/6/2020
*/


#include <iostream>
#include "cat.h"
using namespace std;

int main () {

	int size = 4;
	Cat *kittens = new Cat[size];


	int kittycounter =0;
	int exit =-1;

	do
	{
		
		if (kittycounter != 0 ) {cin.ignore();}
		else {cout << endl;}
		
		string catyarn= "oops"; //temp string used for storage
		float catnoms = -1; //temp used for int storage
		char catparts = 'f'; //temp used for char storage

		cout << "Please enter cat " << kittycounter +1 << "'s name: ";
		getline(cin, catyarn); kittens[kittycounter].setName(catyarn);

		cout << endl;

		cout << "Please enter cat " << kittycounter +1 << "'s breed: ";
		getline(cin, catyarn); kittens[kittycounter].setBreed(catyarn);

		cout << endl;

		cout << "Please enter cat " << kittycounter +1 << "'s ID: ";
		getline(cin, catyarn); kittens[kittycounter].setID(catyarn);

		cout << endl;

		cout << "Please enter cat " << kittycounter +1 << "'s weight: ";
		cin >> catnoms; kittens[kittycounter].setWeight(catnoms);	

		cout << endl;

		do {
			cout << "Please enter cat " << kittycounter +1 << "'s gender (m or f): ";
			cin >> catparts;
		} while (catparts != 'm' & catparts != 'f');
		kittens[kittycounter].setGender(catparts);

		cout << endl;

		do {
			cout << "Has cat " << kittycounter +1 << " been spayed or neutered?" << endl;
			cout << "Please enter y or n: ";
			cin >> catparts; 
		} while (catparts != 'y' & catparts != 'n');
		kittens[kittycounter].setSpayed(catparts);

		cout << endl;
		cin.ignore();

		cout << "Please enter cat " << kittycounter +1 << "'s description: ";
		getline(cin, catyarn); kittens[kittycounter].setDescription(catyarn); //fix

		cout << endl;

		cout << "Please enter cat " << kittycounter +1 << "'s comments: ";
		getline(cin, catyarn); kittens[kittycounter].setComments(catyarn); //fix

		++kittycounter;
		cout << endl;

		if (kittycounter == size)
			{ cout << "No more room for kitties!" << endl; exit = -1;}
		else {

			do
			{
				cout << "Do you want to continue entering kittens?" << endl;
				cout << "Please enter y or n: ";
				cin >> catparts;
			} while (catparts != 'y' & catparts != 'n');

			if (catparts == 'y')
				{ exit = 1; }
			else if (catparts == 'n')
				{ cout << endl << "stopping the kitties!" << endl << endl; exit = -1; }
			else
				{ cout << "Something went wrong, stopping the kitties." << endl << endl; exit = 1;}
		}

		cout << endl;	

	} while (exit != -1);

	for (int n =0; n<kittycounter; ++n)
	{
		cout << "------------------------------------" << endl;
		cout << "Info for cat #" << n+1 << endl;
		cout << "------------------------------------" << endl;
		kittens[n].printInfo();
		cout << endl;
	}

	delete [] kittens;
	return 0;
}