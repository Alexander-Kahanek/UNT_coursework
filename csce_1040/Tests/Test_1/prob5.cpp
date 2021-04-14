/*
Name: Alexander Kahanek
Problem: #5
*/

#include <iostream>
#include "prob5.h"
using namespace std;

int main()
{

	int SIZE; //in range [1,13]
	do{
		cout << "Please enter number of turkeys: "; cin >> SIZE;
	}while( SIZE < 1 | SIZE > 13);
	
	struct turkey *turkey_arr = new turkey[SIZE];
	cout << SIZE << endl;

	bool tbool=1; //temp  bool used for char check
	int num_male=0; //counter for males
	int num_female=0; //counter for females
	float total_weight=0; //counter for total weight
	float avg_weight =0; //var for average weight

	cin.ignore();

	for (int i=0; i<SIZE; ++i) {
		
		cout << "Please enter turkey " <<i+1<<"'s name: "; getline(cin, turkey_arr[i].name);
		
		cout << "Please enter turkey " <<i+1<<"'s type: "; getline(cin, turkey_arr[i].type);
	
		do {
			cout << "Please enter turkey " <<i+1<<"'s gender (m or f): ";
			cin >> turkey_arr[i].gender;

			
			if (turkey_arr[i].gender == 'm')
			{
				tbool = 0;
				num_male += 1;
			}
			else if (turkey_arr[i].gender =='f')
			{
				tbool = 0;
				num_female += 1;
			}
			else
			{
				tbool = 1;
			}
			
		}while(tbool != 0);
	
		do {
			cout << "Please enter turkey " <<i+1<<"'s weight: ";	
			cin >> turkey_arr[i].weight;
			total_weight += turkey_arr[i].weight;
		}while(turkey_arr[i].weight <0 | turkey_arr[i].weight >50 );

		do {
			cout << "Please enter turkey " <<i+1<<"'s age: ";
			cin >> turkey_arr[i].age;
		}while(turkey_arr[i].age <0 | turkey_arr[i].age >99 );

		
		cin.ignore();

	}

	avg_weight = total_weight/SIZE;

	cout << endl;
	cout << "The total number of male Turkeys are: " << num_male << endl;
	cout << "The total number of female Turkeys are: " << num_female << endl;
	cout << "The total weight of all turkeys is: " << total_weight << endl;
	cout << "The average weight of the turkeys is: " << avg_weight << endl << endl;


	cout << "Turkey" << setw(12) << "  Name"<< setw(16) << "       Type" << "\t" << "Gender"<< "\t\t" << "Age" << "\t\t" << "Weight" << endl;
	for (int i=0; i<SIZE; ++i)
	{
		cout << i+1 << "\t";
		cout << setw(10) << turkey_arr[i].name << "\t";
		cout << setw(10) << turkey_arr[i].type << "\t";
		cout << turkey_arr[i].gender << "\t\t";
		cout << turkey_arr[i].age <<"(years)" << "\t";
		cout << turkey_arr[i].weight<<"(lbs)" << endl;
	}

	delete [] turkey_arr;

	return 0;
}