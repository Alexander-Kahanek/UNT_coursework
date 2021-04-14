//luxury.h limo *any* pass
#include <iostream>
#include "driver.h"
using namespace std;


class Luxury: public Driver{

	public:
		int cc; //cargo capacity
		string amenities; //features of class
		Luxury();
		~Luxury();
		void printDriver();

};