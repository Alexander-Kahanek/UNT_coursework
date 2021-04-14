//animal.h
#include <iostream>
using namespace std;

class Animal {
	private:
		string name;
		float weight;
		char gender;
		string desc;

	public:
		//create
		Animal();
		Animal(string n, float w, char g, string d);
		
		//set
		void set_name(string x);
		void set_weight(float x);
		void set_gender(char x);
		void set_desc(string x);
		
		//get
		string get_name();
		float get_weight();
		char get_gender();
		string get_desc();


		//else
		virtual void printinfo();
};

