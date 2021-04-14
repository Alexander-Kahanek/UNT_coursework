/*
Author:		Alexander Kahanek (alexanderkahanek@my.unt.edu)
Date: 		7 NOV 2019
Instructor: 	Pradhumna Shrestha
Description:	Finds max value in file "Act8A.txt"
*/	

#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
	int file_int; // stores integers from file
	int max_int; // stores current max value
	
	ifstream fin; //declare cin name
	fin.open("Act8A.txt"); // open file


	fin >> file_int; //take first value
	while (fin >> file_int) // read all other numbers
	{
		if (file_int > max_int)
		{
			max_int = file_int;
		}
	}

	fin.close();
	
	cout << "The max value is: " << max_int << endl;



	return 0;
}