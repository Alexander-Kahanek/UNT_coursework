//basic.h 2-4 pass
#include <iostream>
#include "driver.h"
using namespace std;


class Basic: public Driver{

	public:
		int cc; //cargo capacity
		string amenities; //features of class
		Basic();
		~Basic();
		void printDriver();

};