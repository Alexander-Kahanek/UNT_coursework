/*
Author: Alexander Kahanek (alexander.kahanek@my.unt.edu)
Date: 9/5/2019
Instructor:
Description: 	Program calculates the total area of a ractangle with a triangle ontop,
		where the length of the rectangle = base of the triangle.
*/

#include <iostream>
using namespace std;

int main()
{
	float l; //length for ractangle
	float w; //width for rectangle and base for height
	float h; //height for triangle
	float A; //area for total shape
	
	cout << "Enter the Length for your rectangle (in inches): ";
	cin >> l;

	cout << "Enter the Width/Base for your rectangle/triangle (in inches): ";
	cin >> w;

	cout << "Enter the Height for your triangle (in inches): ";
	cin >> h;

	
	A = l*w + .5*w*h; //formula for rectangle + triangle b=w

	cout << "The total Area is: " << A << " in^2" << endl;

	return 0;
}