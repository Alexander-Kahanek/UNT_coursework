//horse.cpp
#include "horse.h"
using namespace std;

Horse::Horse(){
id = "none";
breed = "none";
spay = 0;
comments = "none";
}

Horse::Horse(string i, string b, bool s, string c){
id = i;
breed = b;
spay = s;
comments = c;
}

void Horse::set_id(string x) {id = x;}
void Horse::set_breed(string x) {breed = x;}
void Horse::set_spay(bool x) {spay = x;}
void Horse::set_comments(string x) {comments = x;}

string Horse::get_id() { return id;}
string Horse::get_breed() { return breed;}
bool Horse::get_spay() { return spay;}
string Horse::get_comments() { return comments;}

void Horse::printinfo(){
cout << "ID: " << id << endl;
cout << "BREED: " << breed << endl;
cout << "SPAY: ";

if (spay ==0) {cout << "NOT SPAYED";}
else if (spay == 1) {cout << "IS SPAYED";}
cout << endl;

cout << "COMMENTS: " << comments << endl;

Animal::printinfo();

}
