/*
Author:		Alexander Kahanek (alexanderkahanek@my.unt.edu)
Date: 		7 NOV 2019
Instructor: 	Pradhumna Shrestha
Description:	Reads a text file, and outputs it
*/	

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void get_stream (ifstream& in_s, ofstream& out_s);

int main ()
{
	char ch;
	ifstream in_s;
	ofstream out_s;
	
	get_stream(in_s, out_s);
	cout << "*** Here are the contents of the input file ***" << endl << endl;

	while (!in_s.eof()) //ends when loop reaches end of file
	{
		in_s.get(ch); //grabs strings until endline
		cout << ch; //couts file into compiler
		out_s.put(ch); //copy's file into new output file
	}

	cout << endl << "*** Done writing the contents of the file ***" << endl;

	in_s.close();

	return 0;
}

void get_stream (ifstream& in_s, ofstream& out_s)
{
	char input_file[15];
	char output_file[15];

	cout << "Enter the name of the input file: ";
	cin >> input_file;

	cout << "Enter the name of the output file: ";
	cin >> output_file;


	in_s.open(input_file);
	if (in_s.fail())
	{
		cout << "Unable to open input file " << input_file << endl;
		exit(EXIT_FAILURE);
	}

	out_s.open(output_file);
	if (out_s.fail())
	{
		cout << "Unable to open input file " << output_file << endl;
		exit(EXIT_FAILURE);
	}

	
	return;
}