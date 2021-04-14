/*
Author:		Alexander Kahanek (alexanderkahanek@my.unt.edu)
Date: 		29 NOV 2019
Instructor: 	Pradhumna Shrestha	
Description:	- Program designed to have user find predetermined colonies of ants.
		- Starting at column 2, user enters row until they find a colony.
		- If colony was not found, subtract ants in that spot with total ants.
		- If colony was found, continue to next column or complete.

How:		* If player starts a new game, program initializes all arrays with new values.
			- If user continues a game, program loads previous save data from file.
		* Program then starts the game, asking user to enter row to attack until a colony is found.
		* When user finds a colony, program asks if user wants to save the game 
			- If user saves game, program copies all data to a new save file, then exits the game
		* If user does not save, program automatically goes to the next column and repeats until last column is completed
		* Upon completion, game prints message then quits the game, also deleting all allocated dynamic memory.
*/

#include "ark0174HW4.h"

int main ()
{
	//****** PRINTS ALL GAME INFO *********
	Print_Stud_Info (); //student info
	Print_Game_Info (); //game info
	
	//******** INITIALIZES ALL ARRAYS FOR GAME ************
	int **main_array; //array that holds all numbers of ant armies
	int **colony_array; //1st row designates the column number, 2nd row designates the row that the colony is placed on.
	int **move_array; //1st col set as 2, everything else is 0 until user goes to spot, then spot is 1, added armies are 3.
	main_array = new int*[SIZE];
	colony_array = new int*[2];
	move_array = new int*[SIZE];
		
	for (int i=0; i<SIZE; ++i)
	{
		main_array[i] = new int [SIZE]; // SIZE x SIZE 2D array
		move_array[i] = new int[SIZE]; // SIZE x SIZE 2D array
	}
	for (int i=0; i<2; ++i)
	{
		colony_array[i] = new int[SIZE]; // 2 x SIZE 2D array
	}

	/* //********* USED FOR PROGRAM CHECKS ********
	Print_all_arrays (main_array, colony_array, move_array); //this is used to check all program arrays
	Print_user_main_array (main_array, move_array);
   	*/

	//******* INITIALIZES ALL VARIABLES FOR GAME *********
	char play_game; //placeholder for user entered value
	char new_game; //placeholder for user entered value
	int *user_column; //variable used for keeping track of users current column position
	user_column = new int; 
	int ants =0; //sets number of ants at 0 to start, changes inside functions
	
	//******* CHECKS USER RESPONSE ********
	do
	{
		cout << "*******************************" << endl;
		cout << "* Do you want to play a game? *" << endl;
		cout << "*           Y: Yes.           *" << endl;
		cout << "*           N: No.            *" << endl;
		cout << "*******************************" << endl;
		cin >> play_game; cout << endl;
		play_game = toupper(play_game);
	} while ((play_game != 'Y') && (play_game != 'N')); //user must enter y, Y, n, N

	//********* STARTS GAME FROM USER RESPONSE ***********
	if (play_game == 'Y')
	{
			cout << "************************************************************" << endl;
			cout << "* Enter C if you would like to continue the previous game. *" << endl;
			cout << "*        Otherwise enter any key to play a new game!       *" << endl;
			cout << "************************************************************" << endl;
			cin >> new_game; new_game = toupper(new_game);
	
			if (new_game != 'C')
			{
				*user_column = 1; //user starts at row 1
				Initialize_all_arrays (main_array, colony_array, move_array, &ants); //sets all arrays to new values
				Play_game (main_array, colony_array, move_array, &ants, user_column); //starts game sequence
			}
			else if (new_game == 'C')
			{
				cout << "Loading last saved game... " << endl;
				Load_game (main_array, colony_array, move_array, &ants, user_column); //loads previous arrays for game
				cout << "Your last saved game has loaded..." << endl;
				Play_game (main_array, colony_array, move_array, &ants, user_column); //starts game sequence
			}
	}
	else if (play_game == 'N')
	{
		cout << "Goodbye..." << endl;
	}

	//********** DELETION OF ARRAYS ***********
	for (int i=0; i<SIZE; ++i)
	{
		delete [] main_array[i];
		delete [] move_array[i];
	}
	for (int i=0; i<2; ++i)
	{
		delete [] colony_array[i];
	}

	delete [] main_array;
	delete [] colony_array;
	delete [] move_array;

	return 0;
}
