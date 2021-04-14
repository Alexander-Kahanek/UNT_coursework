/*
Name: Alexander Kahanek (ark0174)
Teacher: David Keathly
Date: 3/6/2020
*/


#include <iostream>
#include "cat.h"
using namespace std;

Cat::Cat()
{
	name = "none";
	breed = "none";
	weight = 0;
	gender = 'x';
	spayed = 0;
	id = "none";
	description = "none";
	comments = "none";
}
Cat::Cat(string n= "none", string b= "none", float w= 0, char g= 'x', bool s=0, string i= "none", string de= "none", string c= "none")
{
	name = n;
	breed = b;
	weight = w;
	gender = g;
	spayed = s;
	id = i;
	description = de;
	comments = c;

}
void Cat::setBreed(string s) {breed = s;}
void Cat::setWeight(float f) {weight = f;}
void Cat::setName(string s) {name = s;}
void Cat::setGender(char c) {gender = c;}
void Cat::setSpayed(bool b) {spayed = b;}
void Cat::setID(string s) {id = s;}
void Cat::setDescription(string s) {description = s;}
void Cat::setComments(string s) {comments = s;}
string Cat::getBreed() {return breed;}
float Cat::getWeight() {return weight;}
string Cat::getName() {return name;}
char Cat::getGender() {return gender;}
bool Cat::getSpayed() {return spayed;}
string Cat::getID() {return id;}
string Cat::getDescription() {return description;}
string Cat::getComments() {return comments;}
void Cat::printInfo()
{

	cout << "Name: " << name << endl;
	cout << "Breed: " << breed << endl;
	cout << "ID: " << id << endl;
	cout << "Weight: " << weight << endl;
	cout << "Gender: ";
	if (gender == 'm') {cout << "MALE" << endl;}
	else if (gender == 'f') {cout << "FEMALE" << endl;}
	else if (gender == 'x') {cout << "UNKNOWN" << endl;}


	cout << "Spayed or Neutered: ";
	if (spayed == 0) {cout << "NO" << endl;}
	else if (spayed == 1) {cout << "YES" << endl;}
	
	cout << "Description: " << description << endl;
	cout << "Comments: " << comments << endl;
}
