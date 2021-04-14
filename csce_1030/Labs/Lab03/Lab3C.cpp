/*
Author: Alexander Kahanek (alexander.kahanek@my.unt.edu)
Date: 9/12/19
Instructor: Pradhumna Shrestha
Description: Produces the amount for the customer, after discount is applied.
*/

#include <iostream>
using namespace std;

int main ()
{

float initialPrice;
const float discount = 0.1275;
double  actualPrice;

cout << "Please enter the price of your item: ";
cin >> initialPrice;

actualPrice = initialPrice - (initialPrice * discount);

cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);

cout << "The price of your item, after the discount is: " << actualPrice << endl;

return 0;
}