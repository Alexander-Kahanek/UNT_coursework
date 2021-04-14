/*
Name: Alexander Kahanek (ark0174)
Teacher: David Keathly
Date: 3/6/2020
*/


#include <iostream>
using namespace std;

class Cat {
	private:
		string name;
		string breed;
		float weight;
		char gender;
		bool spayed;
		string id;
		string description;
		string comments;


	public:
		Cat();
		Cat(string name, string breed, float weight, char gender, bool spayed, string id, string description, string comments);
		void setBreed(string s);
		void setWeight(float f);
		void setName(string s);
		void setGender(char c);
		void setSpayed(bool b);
		void setID(string s);
		void setDescription(string s);
		void setComments(string s);
		string getBreed();
		float getWeight();
		string getName();
		char getGender();
		bool getSpayed();
		string getID();
		string getDescription();
		string getComments();
		void printInfo();

};