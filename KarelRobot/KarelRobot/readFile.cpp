#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Beeper.h"
using namespace System;


///////////////////////////////////////////////////////////
//Function: Find out the x and y from a string
//return true - has X and Y 
//		false - no data
//parameters:
//string - has X and Y coordinates
///////////////////////////////////////////////////////////
bool findInfo(std::string my_string, std::string& keyword, int& X, int& Y, int& Z, int& A)
{
	using namespace std;
	string x[5];
	int index = 0;
	string::iterator my_iter;
	for (my_iter = my_string.begin(); my_iter != my_string.end(); my_iter++)
	{
		//cout << *my_iter;
		if (*my_iter != ' ')
			x[index] = x[index] + *my_iter;
		else
			index++;
		if (index > 1)
			break;
	}

	//check if we have all the data, if not then return false;
	if (index < 1)
		return false;

	/*cout << "end of " << my_string << endl;
	cout << x[0] << endl << x[1] << endl;*/

	keyword = x[0];
	X = std::stoi(x[1]);
	Y = std::stoi(x[2]);
	Z = std::stoi(x[3]);
	A = std::stoi(x[4]);
	

	//test
	return true;
};

///////////////////////////////////////////////////////////
//Function: read line from a file.
//return true - has data
//		false - no data
//parameters:
//char arr[]: output array
//int max_array_size: max array can be read
//int number_read: the number of the char has been read
///////////////////////////////////////////////////////////
bool readFromFile(array<System::Int32, 2>^ twoDArray, int& number_read)
{
	using namespace std;

	ifstream instream;
	ofstream outstream;
	const string INPUTFILENAME = "specifics.txt";
	instream.open(INPUTFILENAME);

	string strRead;
	string keyword;
	int position = 0; //this will be used incremently to fill characters in the array 
	using namespace std;
	while (!instream.eof())
	{
		//instream.get(array[position]); //reading one character from file to array
		getline(instream, strRead); //reading one character from file to array

		int x, y, z, a;
		bool flag = findInfo(strRead, keyword, x, y, z, a);
		if (!flag)
			break;
		//cout << "X: " << x << "   Y: " << y << endl;

		if (keyword == "World")
		{
			//Call constructor to initialize
		}
		else if (keyword == "Robot")
		{
			//call robot constructor
		}
		else if (keyword == "Wall")
		{
			//call wall constructor
		}
		else if (keyword == "Beeper")
		{
			using namespace System;
			Beeper::Beeper(x, y, z);
		}
		//twoDArray[position, 0] = x;
		//twoDArray[position, 1] = y;

		position++;
	}

	instream.close();
	number_read = position;
	if (number_read == 0)
		return false;
	else
		return true;
};