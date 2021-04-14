/*
Author: Alexander Kahanek (alexander.kahanek@my.unt.edu)
Date: 9/12/19
Instructor: Pradhumna Shrestha
Description: Calculates the surface area of any given cone, with integer radius and height.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main ()
{

const float PI = 3.14;
int radius;
int height;
float surfaceArea;

cout << "Please Enter Radius: ";
cin >> radius;

cout << "Please Enter Height: ";
cin >> height;

surfaceArea = PI * static_cast<float>(radius) * (radius + sqrt(pow(radius,2.0) + pow(height,2.0)));

cout << "The Surface Area of your cone is: " << surfaceArea << endl;

return 0;
}