/*
Name: Alexander Kahanek
Date: 3/28/20
Class: CSCE 1040
*/

#include <iostream>
#include <vector>
#include "mouse.h"

using namespace std;

int main()
{

	vector<Mouse> mice;

	for (int i=0; i < 6; ++i)
	{
		class Mouse M;

		string tempstr;
		float tempf;
		char tempch;

		cout << "Please enter the name of mouse #" << i+1 << ": ";
		getline(cin, tempstr);
		M.setName(tempstr);

		cout << "Please enter the Breed of mouse #" << i+1 << ": ";
		getline(cin, tempstr);
		M.setBreed(tempstr);

		do{
			cout << "Please enter the weight of mouse #" << i+1 << ": ";
			cin >> tempf;
		}while (tempf <0);
		
		M.setWeight(tempf);

		do{
			cout << "Please enter the gender of mouse #" << i+1 << endl;
			cout << "m - male || f - female || x - unknown: ";
			cin >> tempch; 
		} while(tempch != 'm' & tempch != 'f' & tempch != 'x');

		M.setGender(tempch);

		cin.ignore();

		cout << "Please enter the Favorite Food of mouse #" << i+1 << ": ";
		getline(cin, tempstr);
		M.setFood(tempstr);

		cout << "Please enter the Color of mouse #" << i+1 << ": ";
		getline(cin, tempstr);
		M.setColor(tempstr);

		cout << "Please enter additional comments for mouse #" << i+1 << ": ";
		getline(cin, tempstr);
		M.setComments(tempstr);

		mice.push_back(M);

		cout << endl;
	}

	int cnt=1;

	for (auto itr = mice.begin(); itr != mice.end(); ++itr)
	{
		cout << "**** Mouse #" << cnt << " ****" << endl;
		itr->print();
		cout << endl;
		++cnt;
	}



}