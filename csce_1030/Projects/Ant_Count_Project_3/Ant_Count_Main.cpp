/*
Author:		Alexander Kahanek (alexanderkahanek@my.unt.edu)
Date: 		27 OCT 2019
Instructor: 	Pradhumna Shrestha	
Description:	- Program designed to follow the path of mininum values of Rows.
		- Starting at row 1, find min of row.
		- Go to next row based on column the mininum value was found.
		- No repeating rows, ie, must hit every row once.

How:		* Program transfers the main arrays' row values into TEMPARRAY row 1,
			and their corresponding column into row 2.
		* Program then sorts TEMPARRAY row 1 from least to highest, 0 will always be first,
			corresponding columns follow.
		* Program then finds the next column to check in main array, based off our new TEMPARRAY,
			checking if it has been there before, it stores this info into ArrPath.
		* Program then sorts the next row based off what was stored into ArrPath, then repeats until it hits all rows
		* Program then sorts ArrPath into OrderPath array,
			OrderPath array row 1 - move taken, ie, what order.
			OrderPath array row 2 - corresponding column for move taken.
		* Program then prints info from OrderPath row 2.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 10; //global constant for SIZE
enum IntegerToAlpha {A=0, B, C, D, E, F, G, H, I, J}; //global enum, used for printing final path

// ALL FUNCTIONS USED ** DESCRIPTIONS AT END // **************************************
// ***********************************************************************************
void Print_Stud_Info ();
void Ant_Hunch ();
void Array_Initializer (int antPher[][SIZE]);
void Print_Pher_Arr (int antPher[][SIZE]);
void Sort_Arr_Row (int antPher[][SIZE], int ArrPath[], int TEMPARRAY[][SIZE], int Row);
void Print_TEMPARRAY (int TEMPARRAY[][SIZE]);
void TEMPARRAY_to_ArrPath (int TEMPARRAY[][SIZE], int ArrPath[], int& NextMove);
void Check_Whole_antPher (int antPher[][SIZE], int TEMPARRAY[][SIZE], int ArrPath[]);
int FIND_NEXT_MOVE (int ArrPath[], int NextMove);
void Print_ArrPath (int ArrPath[]);
void Print_Whole_Path (int ArrPath[]);
void ArrPath_to_OrderPath (int ArrPath[], int OrderPath[][SIZE]);
void Print_OrderPath (int OrderPath[][SIZE]);
// ***********************************************************************************
// END OF FUNCTIONS USED // **********************************************************

//**********************************************************************************************************
// ************************************ MAIN FUCNTION ******************************************************
int main ()
{
	int antPher[SIZE][SIZE]; // ant pheremone array
	int ArrPath[SIZE]= {0,0,0,0,0,0,0,0,0,0}; //array for path taken
	int TEMPARRAY[2][SIZE]; // array to store sorted row and cols from one main array row

	Print_Stud_Info (); // prints my info
	Ant_Hunch (); // prints program info
	Array_Initializer (antPher); //initializes array
	Print_Pher_Arr (antPher); //prints array

	Check_Whole_antPher (antPher, TEMPARRAY, ArrPath);
	Print_Whole_Path (ArrPath);


	return 0;
}
//**********************************************************************************************************
// function used to print student info
void Print_Stud_Info () 
{
	cout << "\t+-------------------------------------------------------+" << endl;
	cout << "\t|           Computer Science and Engineering            |" << endl;
	cout << "\t|            CSCE 1030 - Computer Science I             |" << endl;
	cout << "\t| Alexander Kahanek ark0174 alexanderkahanek@my.unt.edu |" << endl;
	cout << "\t+-------------------------------------------------------+" << endl << endl;
}
//**********************************************************************************************************
// function used to print program promt
void Ant_Hunch ()
{
	cout << "\t    W e l c o m e   t o   A n t h o n y's   h u n c h" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "This program will set up a matrix that represents the pheromone levels" << endl;
	cout << "between ant colonies. Anthony's objective is to the find a path least" << endl;
	cout << "taken by the other ants in the hopes of finding food to last through the" << endl;
	cout << "winter" << endl;
	cout << "------------------------------------------------------------------------" << endl << endl;
}
//**********************************************************************************************************
// function used to initialize all of our main array
void Array_Initializer (int antPher[][SIZE] ) //initializes array
{
	srand(time(NULL));

	for (int i=0; i<SIZE; ++i)
	{
		for (int k=0; k<SIZE; ++k)	
		{
			if ( i == k ) // makes diagnal 0
			{
				antPher[i][k] = 0;			
			}
			else if ( i==0 && k==1) // keeps spot [0][1] at 16
			{
				antPher[0][1] = 16;
			}
			else // everything else gets random number [1,20]
			{
				antPher[i][k] = rand() % 20 +1;
			}
		}
	}

}
//**********************************************************************************************************
// function used to print our main array
void Print_Pher_Arr (int antPher[][SIZE] ) //prints array
{	
	cout << "     A      B      C      D      E      F      G      H      I      J" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	for (int i=0; i<SIZE; ++i)
	{
		char rowChar = 'A' +i; //changes letter for each row
		cout << rowChar << " | "; // Prints 'A |	'

		for (int k=0; k<SIZE; ++k)
		{
			if (antPher[i][k] < 10) //condition for adding leading 0
			{
				cout << "0" << antPher[i][k] << "     ";
			}
			else
			{
				cout << antPher[i][k] << "     ";
			}
		}
		cout << endl;
	}


}
//**********************************************************************************************************
// function used to take any given row of our main array and sort it into TEMPARRAY.
// first row in TEMPARRAY is pheromone levels from smallest to largest, it will always start with a 0
// second row is to store what column that pheremone level came from, first value will always be itself
void Sort_Arr_Row (int antPher[][SIZE], int TEMPARRAY[][SIZE], int Row)
{
	for (int i=0; i<1; ++i)
	{
		for (int k=0; k<SIZE; ++k)
		{
			TEMPARRAY[i][k]=antPher[Row][k];
			TEMPARRAY[i+1][k]=k;
		}
	}

	int temp=0;

	for (int k=0; k<SIZE; ++k)
	{
		for (int n=k+1; n<SIZE; ++n)
		{
			if (TEMPARRAY[0][k] > TEMPARRAY[0][n])
			{
				//swap top row - the numbers
				temp = TEMPARRAY[0][k];
				TEMPARRAY[0][k] = TEMPARRAY[0][n];
				TEMPARRAY[0][n] = temp;

				//swap bottom row - the rows
				temp = TEMPARRAY[1][k];
				TEMPARRAY[1][k] = TEMPARRAY[1][n];
				TEMPARRAY[1][n] = temp;

			}
		}	
	
	}

}
//**********************************************************************************************************
// function used to print TEMPARRAY
void Print_TEMPARRAY (int TEMPARRAY[][SIZE])
{
	cout << "This is TEMPARRAY" << endl;
	for (int i=0; i<2; ++i)
	{
		if (i==0)
		{
			cout << "Numbers | ";
		}
		else
		{
			cout << "Rows    | ";
		}

		for (int k=0; k<SIZE; ++k)
		{
			cout << TEMPARRAY[i][k] << "\t";
		}
		cout << endl;
	}
}
//**********************************************************************************************************
// function used to transfer TEMPARRAY information to ArrPath, giving us where to go next
// function sets up a boolArr for keeping track of where we have been
// funtion runs backwards through TEMPARRAY, so that tempPlace will always be the lowest value pheromone that we havent been to yet
void TEMPARRAY_to_ArrPath (int TEMPARRAY[][SIZE], int ArrPath[], int& NextMove)
{
	int boolArr[SIZE];
	int tempPlace;	

	for (int k=0; k<SIZE; ++k) // sets our temporary array for where we can go
	{
		if ( ArrPath[k] > 0)
		{
			//cout << "Been there" << endl;
			boolArr[k] = 0; //false
		}
		else
		{
			//cout << "Can go here" << endl;
			boolArr[k] = 1; //true
		}
	}

	for (int i=9; i>0; --i) //runs backwards, skips first spot as its always itself, skips places we have been
	{
		if ( (TEMPARRAY[1][i] >= boolArr[TEMPARRAY[1][i]]) && (boolArr[TEMPARRAY[1][i]] != 0) )
		{
			tempPlace = TEMPARRAY[1][i];
		}
	}
	
	++NextMove; // add our next move before assigning, needed as we start a 1 before we do anything
	ArrPath[tempPlace] = NextMove; //assigns ArrPath at the lowest available spot, with the next move
}
//**********************************************************************************************************
// function used to run though every row in our main array
void Check_Whole_antPher (int antPher[][SIZE], int TEMPARRAY[][SIZE], int ArrPath[])
{
	int NextMove = 1; //we start our moves at 1

	
	ArrPath[0] = 1; //Path 1 seperate as we start at index 0 no matter what
	

	for (int k=1; k<SIZE; ++k) // runs 9 times, since we start at row A in main array
	{
		Sort_Arr_Row (antPher, TEMPARRAY, FIND_NEXT_MOVE(ArrPath, NextMove)); //sorts the array for where we are going next
		TEMPARRAY_to_ArrPath (TEMPARRAY, ArrPath, NextMove); // transfers info and updates NextMove automatically
	}
	
	//******* Print ArrPath *******
	//Print_ArrPath(ArrPath);
}
//**********************************************************************************************************
// function finds our next row to visit in main array, based off our NextMove set from function TEMPARRAY_to_ArrPath
// function returns the Go_to value, ie, what row we go to next
int FIND_NEXT_MOVE (int ArrPath[], int NextMove)
{
	int Go_to;

	for (int k=0; k<SIZE; ++k)
	{
		if (ArrPath[k] == NextMove)
		{
			Go_to = k;
		}
	}
	
	return (Go_to);
} 
//**********************************************************************************************************
// function used for printing ArrPath, our full path taken
void Print_ArrPath (int ArrPath[])
{
	cout << "Current ArrPath is" << endl;
	for (int i=0; i<SIZE; ++i)
	{
		char TempChar = 'A' + i;
		cout << TempChar << "\t";
	}
	cout << endl;

	for (int i=0; i<SIZE; ++i)
	{
		cout << ArrPath[i] << "\t";
	}
	cout << endl;
}
//**********************************************************************************************************
// prints array path based off our new ordered path array
void Print_Whole_Path (int ArrPath[])
{
	int Path = 1; //start looking for the first Path
	int OrderPath[2][SIZE];
	

	ArrPath_to_OrderPath (ArrPath, OrderPath); //order path function


	//********* Print Order Path *********
	//Print_OrderPath (OrderPath); //function used to print	
	
	cout << endl << "The Path followed by Anthony is:" << endl;
	for (int k=0; k<SIZE; ++k)
	{
		switch (OrderPath[1][k]) // the switch is the value of the path, it is already ordered by moves
		{
			case A:
				cout << "A----->";
				break;

			case B:
				cout << "B----->";
				break;

			case C:
				cout << "C----->";
				break;

			case D:
				cout << "D----->";
				break;

			case E:
				cout << "E----->";
				break;

			case F:
				cout << "F----->";
				break;

			case G:
				cout << "G----->";
				break;

			case H:
				cout << "H----->";
				break;

			case I:
				cout << "I----->";
				break;

			case J:
				cout << "J----->";
				break;
		}

	}

	cout << endl;
}
//**********************************************************************************************************
// first row path number, so 1, 2, ... , 10, ie, our moves
// second row path taken for that move, ie, the row from our main path
void ArrPath_to_OrderPath (int ArrPath[], int OrderPath[][SIZE])
{
	for (int i=0; i<1; ++i)
	{
		for (int k=0; k<SIZE; ++k)
		{
			OrderPath[i][k]= ArrPath[k];
			OrderPath[i+1][k]=k;
		}
	}

	int temp=0;

	for (int k=0; k<SIZE; ++k)
	{
		for (int n=k+1; n<SIZE; ++n)
		{
			if (OrderPath[0][k] > OrderPath[0][n])
			{
				//swap top row - the path number
				temp = OrderPath[0][k];
				OrderPath[0][k] = OrderPath[0][n];
				OrderPath[0][n] = temp;

				//swap bottom row - the rows taken
				temp = OrderPath[1][k];
				OrderPath[1][k] = OrderPath[1][n];
				OrderPath[1][n] = temp;

			}
		}	

	}
}
//**********************************************************************************************************
// funtion used to print the ordered ArrPath
void Print_OrderPath (int OrderPath[][SIZE])
{

	cout << "Ordered Path is" << endl;
	for (int i=0; i<2; ++i)
	{
		if (i==0)
		{
			cout << "Path order | ";
		}
		else
		{
			cout << "Row taken  | ";
		}

		for (int k=0; k<SIZE; ++k)
		{
			cout << OrderPath[i][k] << "\t";
		}
		cout << endl;
	}

}