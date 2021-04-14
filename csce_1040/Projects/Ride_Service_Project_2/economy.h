//economy.h 2 or less pass
#include <iostream>
#include "driver.h"
using namespace std;


class Economy: public Driver{

	public:
		int cc; //cargo capacity
		string amenities; //features of class
		Economy();
		~Economy();
		void printDriver();

};