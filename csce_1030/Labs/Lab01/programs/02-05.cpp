//DISPLAY 2.5 The string class
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string middle_name, pet_name;
    string alter_ego_name;

    cout << "Enter your middle name and the name of your pet.\n";
    cin >> middle_name;
    cin >> pet_name;

    alter_ego_name = pet_name + " " + middle_name;

    cout << "The name of your alter ego is ";
    cout << alter_ego_name << "." << endl;

    return 0;

{
