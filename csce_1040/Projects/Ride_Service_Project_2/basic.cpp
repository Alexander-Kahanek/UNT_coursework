//basic.cpp
#include <iostream>
#include "basic.h"


Basic::Basic(){cc=2; amenities="test";}

Basic::~Basic(){}

void Basic::printDriver(){ Driver::printDriver(); cout << "I am basic" << endl;}