#ifndef ark0174HW4
#define ark0174HW4

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

const int SIZE = 10;

void Print_Stud_Info ();
void Print_Game_Info ();
void Initialize_all_arrays (int **main_array, int **colony_array, int **move_array, int *ants);
void Print_all_arrays (int **main_array, int **colony_array, int **move_array);
void Print_user_main_array (int **main_array, int **move_array);
void Play_game (int **main_array, int **colony_array, int **move_array, int *ants, int *user_column);
void Round_X (int **main_array, int **colony_array, int **move_array, int *ants, int *user_column);
void Save_game (int **main_array, int **colony_array, int **move_array, int *ants, int *user_column);
void Load_game (int **main_array, int **colony_array, int **move_array, int *ants, int *user_column);

using namespace std;

#endif
