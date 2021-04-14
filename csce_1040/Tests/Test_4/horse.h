//horse.h
#include <iostream>
#include "animal.h"
using namespace std;

class Horse: public Animal{

	private:
		string id;
		string breed;
		bool spay; //0=no, 1=yes
		string comments;

	public:
		Horse();
		Horse(string i, string b, bool s, string c);

		void set_id(string x);
		void set_breed(string x);
		void set_spay(bool x);
		void set_comments(string x);

		string get_id();
		string get_breed();
		bool get_spay();
		string get_comments();

		void printinfo();

};