#include "mouse.h"

using namespace std;


Mouse::Mouse()
{
	name = "none";
	breed = "none";
	weight = 0.0;
	gender = 'x';
	fav_food = "none";
	color = "none";
	comments = "none";
}

Mouse::Mouse(string n, string b, float w, char g, string f, string co, string com)
{
	name = n;
	breed = b;
	weight = w;
	gender = g;
	fav_food = f;
	color = co;
	comments = com;
}

void Mouse::setName(string n) {name = n;}
void Mouse::setBreed(string b) {breed = b;}
void Mouse::setWeight(float w) {weight = w;}
void Mouse::setGender(char g) {gender = g;}
void Mouse::setFood(string f) {fav_food = f;}
void Mouse::setColor(string co) {color = co;}
void Mouse::setComments(string com) {comments = com;}

string Mouse::getName(){return (name);}
string Mouse::getBreed(){return (breed);}
float Mouse::getWeight(){return (weight);}
char Mouse::getGender(){return (gender);}
string Mouse::getFood(){return (fav_food);}
string Mouse::getColor(){return (color);}
string Mouse::getComments(){return (comments);}

void Mouse::print()
{
	cout << "Name: " << name << endl;
	cout << "Breed: " << breed << endl;
	cout << "Weight: " << weight << endl;
	cout << "Gender: " << gender << endl;
	cout << "Food: " << fav_food << endl;
	cout << "Color: " << color << endl;
	cout << "Comments: " << comments << endl;
}
