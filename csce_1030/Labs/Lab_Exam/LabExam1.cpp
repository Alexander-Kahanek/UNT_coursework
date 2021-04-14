#include <iostream>
#include <cmath> //needed for math functions
#include <string> //needed for getline funtion
using namespace std;

int main ()
{

	int my_int = 5;
	double my_dbl = sqrt(2);
	double test;
	

	test = my_int/my_dbl;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);

	cout.precision(2);
	cout << "This is you value at precision 2: " << test << endl;
	
	cout.precision(3);
	cout << "This is you value at precision 3: " << test << endl;

	cout.precision(12);
	cout << "This is you value at precision 12: " << test << endl;

	printf("This is your int %d \n", my_int);
	printf("This is your double %lf \n", my_dbl);

	printf("Please enter any number ");
	scanf("%lf", &test);
	printf("this is your number %lf \n", test);
	
	string my_string;
	cout << "Please enter a phrase" << endl;
	cin.ignore (); //needed to flush out previous cin's
	getline(cin, my_string);

	cout << "This is your phrase: " << my_string << endl;

	int var1 = 5;
	int var2 = 9;
	//int finalVal; //this is wrong as it will only store the integer
	double finalVar; //must store the value in a float or double

	finalVar = static_cast<double>(var1)/var2;

	cout << "If this worked, you will see decimal points: " << finalVar << endl;

	srand(time(NULL));
	
	int random;
	random = rand()%51 +1;
	
	cout << "The range will be between 1 and 50: " << random << endl;

	return 0;
}