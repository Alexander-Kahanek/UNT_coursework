/*
Author:		Alexander Kahanek (alexanderkahanek@my.unt.edu)
Date: 		17 OCT 2019
Instructor: 	Pradhumna Shrestha
Description:	Takes grades from user, checks if grade is >= 60, outputs the passing and failing grades
*/	

#include <iostream>
using namespace std;

int main ()
{
	const int N=10;
	int grade[N];
	int pass[N];
	int fail[N];
	int passed=0;
	int failed=0;

	for (int i=0; i<N; ++i) // for loop for getting user input
	{
		cout << "Enter grade of student #"<< i+1 << ": ";
		cin >> grade[i];
	}

	for (int i=0; i<N; ++i) // for loop for checking if pass or fail
	{	
		
		if ( grade[i] >= 60 )
		{
			pass[passed] = grade[i];
			++passed;
		}
		else
		{
			fail[failed] = grade[i];
			++failed;
		}	
	} 
	
	cout << "You entered:"<<endl;
	for (int i=0; i<N; ++i) // cout for display for student grades
	{
		cout << "Grade for student #" << i+1 << ": " << grade[i] << endl;
	}

	cout << "The number of students that passed are: " << passed << endl;
	for (int i=0; i<passed; ++i) // display for passing grades
	{
		cout << "Passing grades for student #" << i+1 << ": " << pass[i] << endl;
	}

	cout << "The number of students that failed are: " << failed << endl;
	for (int i=0; i<failed; ++i) // display for failing grades
	{
		cout << "Failing grades for student #" << i+1 << ": " << fail[i] << endl;
	}

	return 0;
}