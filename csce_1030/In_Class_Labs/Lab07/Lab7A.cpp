/*
Author:		Alexander Kahanek (alexanderkahanek@my.unt.edu)
Date: 		24 OCT 2019
Instructor: 	Pradhumna Shrestha
Description:	Calculates area of a hexagonal prism.
*/

#include <iostream>
#include <cmath>
using namespace std;

//functions used
float calcSideArea ( const float height, const float length );
float calcHexArea ( const float height );
void printSurfArea ( float rect_area, float hex_area);

int main ()
{
	float height;
	float length;
	float hex_area;
	float rect_area;

	cout << "Enter the length of the base edge in feet: ";
	cin >> length;
	
	cout << "Enter the height of the hexagonal prism in feet: ";
	cin >> height;

	rect_area = calcSideArea(length, height); //func calcs all 6 sides
	cout << "The total surface area of all six rectangular sides of the hexagonal prism is " << rect_area << " square feet." << endl;

	hex_area = calcHexArea(length); //func calcs both hexagons
	cout << "The total surface area of the two hexagons is " << hex_area << " square feet" << endl;

	printSurfArea(rect_area, hex_area); //func calcs and prints total

	return 0;
}

float calcSideArea ( const float height, const float length )
{
	float rect_area = 6 * height * length;

	return (rect_area);
}

float calcHexArea ( const float height )
{
	float hex_area = 3 * (sqrt(3) * height * height);
	
	return (hex_area);
}

void printSurfArea ( float rect_area, float hex_area)
{
	float totArea = rect_area + hex_area;

	cout << "The total area of yoyr hexagonal prism is: " << totArea << endl;	
}