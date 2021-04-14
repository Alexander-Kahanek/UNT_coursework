//group.cpp
#include <iostream>
#include "group.h"


Group::Group(){cc=2; amenities="test";}

Group::~Group(){}

void Group::printDriver(){ Driver::printDriver(); cout << "I am group" << endl;}