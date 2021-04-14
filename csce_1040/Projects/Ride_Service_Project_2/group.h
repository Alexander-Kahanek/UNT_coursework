//group.h 5-7 pass
#include <iostream>
#include "driver.h"
using namespace std;


class Group: public Driver{

	public:
		int cc; //cargo capacity
		string amenities; //features of class
		Group();
		~Group();
		void printDriver();

};