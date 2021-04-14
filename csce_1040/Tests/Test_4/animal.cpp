//animal.cpp
#include "animal.h"
using namespace std;

Animal::Animal(){
name = "none";
weight = 0.0;
gender = 'x';
desc = "none";
}

Animal::Animal(string n, float w, char g, string d){
name = n;
weight = w;
gender = g;
desc = d;
}
		
//set
void Animal::set_name(string x) {name = x;}
void Animal::set_weight(float x) {weight = x;}
void Animal::set_gender(char x) {gender = x;}
void Animal::set_desc(string x) {desc = x;}
		
//get
string Animal::get_name() { return name;}
float Animal::get_weight() { return weight;}
char Animal::get_gender() { return gender;}
string Animal::get_desc() { return desc;}

//else
void Animal::printinfo(){
cout << "NAME: " << name << endl;
cout << "WEIGHT: " << weight << endl;
cout << "GENDER: " << gender << endl;
cout << "DESC: " << desc << endl;
}
