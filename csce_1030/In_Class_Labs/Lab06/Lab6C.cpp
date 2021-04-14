/*
Author:		Alexander Kahanek (alexanderkahanek@my.unt.edu)
Date: 		17 OCT 2019
Instructor: 	Pradhumna Shrestha
Description:	Gets matrix from user, checks mins for rows and colums, displays those mins to user.
*/

#include <iostream>
using namespace std;

int main()
{
	const int ROW=3;
	const int COL=4;
	int matrix[ROW][COL];
	int row_min[ROW];
	int col_min[COL];

	for (int i=0; i<ROW; ++i) // for loop for cin of matrix
	{
		for (int k=0; k<COL; ++k)
		{
			cout<< "Enter data for row#" << i+1 << " and column#" << k+1 <<": "; cin >> matrix[i][k];
		}


	}

	cout << "You entered:" << endl;
	for (int i=0; i<ROW; ++i) // for loop for displaying full matrix
	{
		for (int k=0; k<COL; ++k)
		{
			cout << matrix[i][k] << "\t";
		}
		cout << endl;
	}


	int k=0; //to use this value before we enter our second for loop
	for (int i=0; i<ROW; ++i) // for loop for getting row mins
	{
		row_min[i]=matrix[i][k];
		for (int k=0; k<COL; ++k)
		{
			if (matrix[i][k]< row_min[i])
			{
				row_min[i]=matrix[i][k];
			}
		}
	}

	int i=0; //to use this value before we enter our second for loop
	for (int k=0; k<COL; ++k) // for loop for getting col mins
	{
		col_min[k]=matrix[i][k];
		for (int i=0; i<ROW; ++i)
		{
			if (matrix[i][k]< col_min[k])
			{
				col_min[k]=matrix[i][k];
			}
		}
	}


	cout << "Your minimums for each row is: " << endl;
	for (int i=0; i<ROW; ++i) // for loop for displaying row mins
	{
		cout << "row #" << i+1 << ": " << row_min[i] << endl;
	}

	cout << "Your minimums for each col is: " << endl;
	for (int i=0; i<COL; ++i) // for loop for displaying col mins
	{
		cout << "col #" << i+1 << ": " << col_min[i] << endl;
	}

	return 0;
}