#include "ark0174HW4.h"


//**************************************************************************************************************************
//Function used to print student info
//**************************************************************************************************************************
void Print_Stud_Info () 
{
	cout << "\t+-------------------------------------------------------+" << endl;
	cout << "\t|           Computer Science and Engineering            |" << endl;
	cout << "\t|            CSCE 1030 - Computer Science I             |" << endl;
	cout << "\t| Alexander Kahanek ark0174 alexanderkahanek@my.unt.edu |" << endl;
	cout << "\t+-------------------------------------------------------+" << endl << endl;
}
//**************************************************************************************************************************
//Function used to print game info
//**************************************************************************************************************************
void Print_Game_Info ()
{
	cout << "\t\t       Welcome to Anthony's Battle!" << endl;
	cout << "\t----------------------------------------------------------" << endl;
	cout << "\tAnthony the ant has decided that he wants to take over all" << endl;
	cout << "\tthe adjacent ant colonies with his army of ants from colo-" << endl;
	cout << "\tny 'A'. To do this, Anthony's army will attempt to capture" << endl;
	cout << "\tants from columns 'B' through 'J', with at least 1 ant re-" << endl;
	cout << "\tmaining when the column 'J' ant colony is found. Each col-" << endl;
	cout << "\tumn's ant colony is identified with a 0 in one of the rows" << endl;
	cout << "\tfor that column, while patrols are represented by integers" << endl;
	cout << "\tbetween 1 and 10 for the number of ants in that particular" << endl;
	cout << "\tpatrol. On the way to column 'J' if Anthony's army encoun-" << endl;
	cout << "\tters a patrol, the number in the patrol is subtracted from" << endl;
	cout << "\tAnthony's army total. Once his army finds the colony, how" << endl;
	cout << "\tever, any patrols not confronted will be added to his army" << endl;
	cout << "\ttotal. If Anthony makes really good decisions, then he can" << endl;
	cout << "\ttake over all of the adjacent ant colonies; otherwise, his" << endl;
	cout << "\tarmy will be defeated!" << endl;
	cout << "\t----------------------------------------------------------" << endl << endl;
}
//**************************************************************************************************************************
//Function used to set all arrays to new values
//**************************************************************************************************************************
void Initialize_all_arrays (int **main_array, int **colony_array, int **move_array, int *ants)
{
	
	srand(time(NULL));
	*ants = 0; //user starts at 0 ants
	

	for(int k=0; k<SIZE; ++k)
	{
		int temp_r = rand() % SIZE; //grabs random number for random row of colony location
		for (int i=0; i<SIZE; ++i)
		{
			
			if (i == temp_r)
			{
				main_array[i][k] = 0; //sets 0 to one random spot into each column
				colony_array[1][k] =i; //sets the row# into the designated column
				colony_array[0][k] = k; //sets 0-9 in first row, signifing columns
			}
			else
			{
				main_array[i][k] = rand() % 10 +1; //sets random number [1,10] into main_array
			}

					
		}
	}

	//initializes move_array
	for (int k=0; k<SIZE; ++k)
	{
		for (int i=0; i<SIZE; ++i)
		{
			if (k==0)
			{
				move_array[i][k] = 2; //2 is for starting column, since user cant move here
			}
			else
			{
				move_array[i][k] = 0; //everything is 0, since user has not been anywhere
			}

		}
	}

	// sums total ants of Anthony's army
	for (int i=0; i<SIZE; ++i)
	{
		*ants += main_array[i][0];
	}
}
//**************************************************************************************************************************
//Funtion used to print all arrays: main_array, colony_array, move_array : used for funtion checks
//**************************************************************************************************************************
void Print_all_arrays (int **main_array, int **colony_array, int **move_array)
{
	//****** print main_array ***********
	for (int n=0; n<SIZE; ++n)
	{
		char temp_ch = 'A' + n;
		cout << "\t" << temp_ch;
	}
	cout << endl << "+---------------------------------------------------------------------------------------+" << endl;

	for (int i=0; i<SIZE; ++i)
	{
		for (int k=0; k<SIZE; ++k)
		{
			if (k==0)
			{
				cout << i << "|\t";
			}
			cout << main_array[i][k] << "\t";
			
		}
		cout << "|" << endl;
	}
	cout << "+---------------------------------------------------------------------------------------+" << endl<< endl;

	//****** print colony_array ***********
	for(int k=0; k<2; ++k)
	{
		if (k==0)
		{
			cout << "Col:\t";
		}
		else
		{
			cout << "Row:\t";
		}
	
		for (int i=0; i<SIZE; ++i)
		{
			cout << colony_array[k][i] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	//****** print move_array ***********
	for (int n=0; n<SIZE; ++n)
	{
		char temp_ch = 'A' + n;
		cout << "\t" << temp_ch;
	}
	cout << endl << "+---------------------------------------------------------------------------------------+" << endl;

	for (int i=0; i<SIZE; ++i)
	{
		for (int k=0; k<SIZE; ++k)
		{
			if (k==0)
			{
				cout << i << "|\t";
			}
			cout << move_array[i][k] << "\t";
			
		}
		cout << "|" << endl;
	}
	cout << "+---------------------------------------------------------------------------------------+" << endl<<endl;
}
//**************************************************************************************************************************
//Function used to print the main_array for the user
//**************************************************************************************************************************
void Print_user_main_array (int **main_array, int **move_array, int *ants)
{

	for (int n=0; n<SIZE; ++n)
	{
		char temp_ch = 'A' + n;
		cout << "\t" << temp_ch;
	}
	cout << endl << "+-------------------------------------------------------------------------------+" << endl;

	for (int i=0; i<SIZE; ++i)
	{
		for (int k=0; k<SIZE; ++k)
		{
			if (k==0)
			{
				cout << i << "| ";
			}
			
			if (move_array[i][k] == 2) //starting row, show all
			{
				if (main_array[i][k] <10)
				{
					cout << "0" << main_array[i][k] << "\t";
				} 
				else if (main_array[i][k] == 10)
				{
					cout << main_array[i][k] << "\t";
				}

			}
			else if (move_array[i][k] == 1) //user has moved there, and found ant colony or lost ants
			{
				if (main_array[i][k] == 0)
				{
					cout << "AC\t";
				}
				else
				{
					cout << "XX\t";
				}
			}
			else if ((move_array[i][k] == 0) && (*ants > 0)) //user has not been there and still has an army
			{
				cout << "**\t";
			}
			else if ((move_array[i][k] == 0) && (*ants <= 0)) //user has not been here, but has lost their army
			{
				if (main_array[i][k] <10)
				{
					cout << "0" << main_array[i][k] << "\t";
				} 
				else if (main_array[i][k] == 10)
				{
					cout << main_array[i][k] << "\t";
				}
			}
			else if (move_array[i][k] == 3) //user has not been here, but gained these ants
			{
				if (main_array[i][k] <10)
				{
					cout << "0" << main_array[i][k] << "\t";
				} 
				else if (main_array[i][k] == 10)
				{
					cout << main_array[i][k] << "\t";
				}
			}
		}
		cout << "|" << endl;
	}
	cout << "+-------------------------------------------------------------------------------+" << endl<< endl;

}
//**************************************************************************************************************************
//Function used to initiate playing the game
//**************************************************************************************************************************
void Play_game (int **main_array, int **colony_array, int **move_array, int *ants, int *user_column)
{
	char save_quit;
	
	for (int i=0; i<SIZE -1; ++i) //only 9 rounds, as user starts on column 2
	{
		if (i==0)
		{
		cout << "***************************************************" << endl;			
		cout << "* Your army is starting this round with " << *ants << " ants! *" << endl;
		cout << "***************************************************" << endl;
		}
	
		Round_X (main_array, colony_array, move_array, ants, user_column);
		cout << "*****************************************" << endl;	
		cout << "* Your army now has a total of " << *ants << " ants! *" << endl;
		cout << "*****************************************" << endl;	
				
		if (*user_column == 10)	
		{
			cout << endl;
			cout << "*****************************************************" << endl;	
			cout << "* Congratulations! You have colonized all the ants! *" << endl;
			cout << "*         Here is your final board state.           *" << endl;
			cout << "*****************************************************" << endl;
			Print_user_main_array (main_array, move_array, ants);
		}
		else if (*user_column < 10)
		{
			cout << "********************************************************" << endl;
			cout << "* Enter Q if you would like to save and quit your game *" << endl;
			cout << "*         Otherwise enter any key to continue          *"<< endl;
			cout << "********************************************************" << endl;
			cin >> save_quit;
			save_quit = toupper(save_quit);
			
			if (save_quit == 'Q') //initiates saving game
			{
				Print_user_main_array (main_array, move_array, ants);
				Save_game (main_array, colony_array, move_array, ants, user_column);
				cout << "Your game is saved, goodbye!" << endl;
				exit (0);
			}
		}
	}
}
//**************************************************************************************************************************
//Function used to start the next round, based on where user is from user_column value
//**************************************************************************************************************************
void Round_X (int **main_array, int **colony_array, int **move_array, int *ants, int *user_column)
{
	int current_column = *user_column; //to keep track of the current column
	char temp_ch = 'A' + *user_column; //used for output
	int user_row_strike; //value for which row to strike
	int temp_count=0; //temp tracker for total ant loss or gain

	do
	{
		Print_user_main_array (main_array, move_array, ants);
		
		do
		{
			cout << "Enter row position in column " << temp_ch << " to strike: ";
			cin >> user_row_strike; cout << endl;
		} while ((user_row_strike < 0) || (user_row_strike > 9));

		if (move_array[user_row_strike][current_column] == 0) //user has not been there
		{
			if (user_row_strike == colony_array[1][current_column]) //user hit colony
			{
				
				cout << "** Good job! You have hit an enemies colony! **" << endl;
				
				for (int i=0; i<SIZE; ++i)
				{
					if (move_array[i][current_column] == 0) //adds everything not attacked
					{
						temp_count += main_array[i][current_column];
						move_array[i][current_column] = 3;
					}
				}
				
				move_array[user_row_strike][current_column] = 1; //updates moves been to
				Print_user_main_array (main_array, move_array, ants);
				++current_column; //exits loop
			}
			else //user didn't hit colony
			{
				cout << "Oh no! You have hit an enemies Army and you lost "<< main_array[user_row_strike][current_column] <<" ants!" << endl;
				temp_count -= main_array[user_row_strike][current_column]; //subtracts army size that was hit
				move_array[user_row_strike][current_column] = 1; //updates moves been to

				if ((*ants + temp_count) <= 0)
				{
					*ants += temp_count;
					cout << "Oh no! Your army of ants has died! Please play again." << endl;
					Print_user_main_array (main_array, move_array, ants);
					exit (0);
				}
			}
		}
		else if (move_array[user_row_strike][current_column] == 1) //user has been there
		{
			cout << "*************************************************************" << endl;
			cout << "* You have been here already! Choose another row to strike! *" << endl;
			cout << "*************************************************************" << endl;
		}

	} while (*user_column == current_column);

	if (temp_count >0)
	{
		cout << "** Congratulations you have gained " << temp_count << " ants into your army! **" << endl;
	}
	else if (temp_count < 0)
	{
		cout << "** Unfortunately you have lost " << (-1) * temp_count << " ants in your army! **" << endl;
	}
	else //temp_count ==0
	{
		cout << "** Fortunately you came out even in this battle! **" << endl;
	}

	*ants += temp_count;
	*user_column = current_column;
}
//**************************************************************************************************************************
//Funtion used to create and save game data onto file "savedata.dat"
//**************************************************************************************************************************
void Save_game (int **main_array, int **colony_array, int **move_array, int *ants, int *user_column)
{
	ofstream fout;
	fout.open("savedata.dat"); //creates or overrides file "savedata.dat"
	
	if (fout.fail()) //failsafe, not really useful here.
	{
		cout << "File could not be found, could not save your game." << endl;
		exit(1);
	}


	for (int i=0; i<SIZE; ++i) //fouts for main_array
	{
		for (int k=0; k<SIZE; ++k)
		{
			fout << main_array[i][k] << " ";
		}
		fout << endl;
	}

	for (int i=0; i<2; ++i) //fouts for colony_array
	{
		for (int k=0; k<SIZE; ++k)
		{
			fout << colony_array[i][k] << " ";
		}
		fout << endl;
	}

	for (int i=0; i<SIZE; ++i) //fouts for move_array
	{
		for (int k=0; k<SIZE; ++k)
		{
			fout << move_array[i][k] << " ";
		}
		fout << endl;
	}

	fout << *ants << " " << endl;
	fout << *user_column << " " << endl;

	fout.close();
}
//**************************************************************************************************************************
//Funtion designed to load a saved game from "savedata.dat"
//**************************************************************************************************************************
void Load_game (int **main_array, int **colony_array, int **move_array, int *ants, int *user_column)
{
	ifstream fin;
	fin.open("savedata.dat"); //opens previous save file

	if (fin.fail()) //if user has never saved the game
	{
		cout << "File could not be found, you have no save data." << endl;
		exit(1);
	}
	
	for (int i=0; i<SIZE; ++i) //fins for main_array
	{
		for (int k=0; k<SIZE; ++k)
		{
			fin >> main_array[i][k];
		}
	}

	for (int i=0; i<2; ++i) //fins for colony_array
	{
		for (int k=0; k<SIZE; ++k)
		{
			fin >> colony_array[i][k];
		}
	}

	for (int i=0; i<SIZE; ++i) //fins for move_array
	{
		for (int k=0; k<SIZE; ++k)
		{
			fin >> move_array[i][k];
		}
	}

	fin >> *ants;
	fin >> *user_column;

	fin.close();
}
