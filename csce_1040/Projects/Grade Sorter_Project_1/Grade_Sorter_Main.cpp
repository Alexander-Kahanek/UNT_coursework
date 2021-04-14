/*
Author:		Alexander Kahanek (alexanderkahanek@my.unt.edu)
Date: 		29 JAN 2020
Instructor: 	David Keathly	
Description:	- Program designed to read in grades file
		- designed to sort data
		- designed to calculate simple discrete statistics
		- designed to create a new file with stats and sorted data
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

using namespace std;

typedef struct {
	float mean;
	float min;
	float max;
	float median;
	char* name;
}classStats;

int main()
{
	//*** opens file ***//
	ifstream fin;
	fin.open("grades");

	if (fin.fail()) { //failsafe for checking if file exists or not
		cout <<"The file does not exist." << endl;
		exit(1); //exits program
	}

	//*** Variables for storing data ***//
	const int SIZE = 19; // 19 students in file
	string header; //variable for holding header
	student *students_arr = (student *) malloc(sizeof(student)*SIZE);
	for (int i=0; i<SIZE; ++i) {
		students_arr[i].first= new char[20];
		students_arr[i].last= new char[20];
	}

	

	//*** Loop for grabbing data from file ***//
	fin >> header;
	for (int i=0; i<SIZE; ++i) {
		string tempfn;
		string templn;

		fin >> tempfn; //grabs names as strings
		fin >> templn; //grabs names as strings
		fin >> students_arr[i].exam1;
		fin >> students_arr[i].exam2;
		fin >> students_arr[i].exam3;
		
		strcpy( students_arr[i].first, tempfn.c_str()); //copies string to char array
		strcpy( students_arr[i].last, templn.c_str()); //copies string to char array
	}

	int temp_arr[2][SIZE];

	for (int i=0; i<SIZE;  ++i) { //calculates mean of every student
		students_arr[i].mean = (static_cast<float>(students_arr[i].exam1) + students_arr[i].exam2 + students_arr[i].exam3)/3;
		temp_arr[0][i]=students_arr[i].mean;
		temp_arr[1][i]=i;
	}

	for(int x = 0; x < SIZE; x++) {
		for(int y = 0; y < SIZE-1; y++) {
			if(temp_arr[0][y] > temp_arr[0][y+1]) {
				int temp;
				temp = temp_arr[0][y+1];
				temp_arr[0][y+1] = temp_arr[0][y];
				temp_arr[0][y] = temp;

				temp = temp_arr[1][y+1];
				temp_arr[1][y+1] = temp_arr[1][y];
				temp_arr[1][y] = temp;

     			}
		}
	}


	//*** Variables for total data ***//
	classStats classdata;
	classdata.min = students_arr[temp_arr[1][0]].mean; //temp_arr serves as a guide for what index to use
	classdata.max = students_arr[temp_arr[1][18]].mean;
	classdata.median = students_arr[temp_arr[1][9]].mean;
	classdata.mean = 0;

	for (int i=0; i<SIZE; ++i) {
		classdata.mean = classdata.mean + students_arr[temp_arr[1][i]].mean;
	}
	classdata.mean = classdata.mean/SIZE;

	//*** creates new file ***//
	ofstream fout;
	fout.open("class_data.dat");

	//*** loop for writing onto new file with data ***//
	fout << header << "\t"<<"MEAN:"<< setw(7) <<fixed<<setprecision(2)<< classdata.mean << "  MIN:"<< setw(7) <<fixed<<setprecision(2)<< classdata.min << "  MAX:"<< setw(7) <<fixed<<setprecision(2)<< classdata.max << "  MEDIAN:"<< setw(7) << classdata.median <<endl;
	for (int i=0; i<SIZE; ++i) {
		fout << setw(12) << students_arr[temp_arr[1][i]].first << " " << setw(12) << students_arr[temp_arr[1][i]].last << " " << setw(10) <<fixed<<setprecision(2)<< students_arr[temp_arr[1][i]].mean << endl;
	}

	for (int i=0; i<SIZE; ++i) {
		free(students_arr[i].first);
		free(students_arr[i].last);
	}
	free(students_arr);

	fin.close();
	fout.close();

	cout << "Your new data was saved onto 'class_data.dat'." << endl;
  return 0;
}
