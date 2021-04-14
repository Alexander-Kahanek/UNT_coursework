//economy.cpp
#include <iostream>
#include "economy.h"


Economy::Economy(){cc=2; amenities="test";}

Economy::~Economy(){}

void Economy::printDriver(){ Driver::printDriver(); cout << "I am economy" << endl;}