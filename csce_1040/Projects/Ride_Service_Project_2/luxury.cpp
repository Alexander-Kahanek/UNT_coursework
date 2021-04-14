//luxury.cpp
#include <iostream>
#include "luxury.h"


Luxury::Luxury(){cc=2; amenities="test";}

Luxury::~Luxury(){}

void Luxury::printDriver(){ Driver::printDriver(); cout << "I am luxury" << endl;}