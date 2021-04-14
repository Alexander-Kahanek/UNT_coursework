//horsemain.cpp
/*
NAME: ALexander Kahanek
PROF: David Keathly
DESC: Program designed for test 4, using problem 7, animal and horse class
*/


#include "horse.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){

	vector<Horse*> vec;//vector for horse

	//getting
	for(int i=0; i<3; ++i){
		//get all info

		Horse *h=new Horse;

		string ts; //temp string
		float tf; //temp float
		char tc; //temp char
		bool tb; //temp bool
	
		cout << endl;

		cout << "Please enter the ID for the Horse: ";
		getline(cin, ts);
		h->set_id(ts);

		cout << endl;

		cout << "Please enter the NAME for the Horse: ";
		getline(cin, ts);
		h->set_name(ts);

		cout << endl;

		cout << "Please enter the BREED for the Horse: ";
		getline(cin, ts);
		h->set_breed(ts);

		cout << endl;

		do{
			cout << "Please enter the WEIGHT of for the Horse (float >0): ";
			cin >> tf;
		}while(tf<0);
		h->set_weight(tf);

		cout << endl;

		do{
			cout << "Please enter the GENDER of for the Horse"<< endl;
			cout << "m - male" << endl;
			cout << "f - female" << endl;
			cout << "x - unknown" << endl;
			cin >> tc;
		}while(tc != 'm' & tc != 'f' & tc != 'x');
		h->set_gender(tc);

		cout << endl;

		do{
			cout << "Please enter the SPAY/NEUTER status of for the Horse" << endl;
			cout << "y - yes, is spayed or neutered" << endl;
			cout << "n - no, is not spayed or neutered" << endl;
			cin >> tc;
		}while(tc != 'y' & tc != 'n');
		if (tc == 'y') {tb=1;}
		else if (tc == 'n') {tb=0;}
		h->set_spay(tb);

		cin.ignore();

		cout << endl;

		cout << "Please enter the DESCRIPTION for the Horse: ";
		getline(cin, ts);
		h->set_desc(ts);

		cout << endl;

		cout << "Please enter any COMMENTS for the Horse: ";
		getline(cin, ts);
		h->set_comments(ts);

		vec.push_back(h);
	}

	int cnt=1; //track num of horses
	//printing
	for (auto itr = vec.begin(); itr != vec.end(); ++itr)
	{
		cout << "**** Horse #" << cnt << " ****" << endl;
		(*itr)->printinfo();
		cout << endl;
		++cnt;
	}

	//deletion
	for (auto itr = vec.begin(); itr != vec.end(); ++itr)
	{
		delete *itr;
	}
	vec.clear();

	return 0;
}