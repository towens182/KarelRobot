#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Beeper.h"
#include "MyForm.h"


///////////////////////////////////////////////////////////
//Function: Find out the x and y from a string
//return true - has X and Y 
//		false - no data
//parameters:
//string - has X and Y coordinates
///////////////////////////////////////////////////////////
void findInfo(std::string my_string, std::string& keyword, int& X, int& Y, int& Z, int& A)
{
	using namespace std;
	string x[5][5];
	int index, i = 0;
	string::iterator my_iter;
	for (i = 0; i < 5; i++)
	{
		for (my_iter = my_string.begin(); my_iter != my_string.end(); my_iter++)
		{
			//cout << *my_iter;
			if (*my_iter != ' ')
				x[i][index] = x[i][index] + *my_iter;
			else
				index++;
			if (index > 1)
				break;
		}

		//check if we have all the data, if not then return false;
		if (index < 1)
			exit(1);

		/*cout << "end of " << my_string << endl;
		cout << x[0] << endl << x[1] << endl;*/

		keyword = x[i][0];
		X = std::stoi(x[i][1]);
		Y = std::stoi(x[i][2]);
		Z = std::stoi(x[i][3]);
		A = std::stoi(x[i][4]);

	}
	//test

}

///////////////////////////////////////////////////////////
//Function: read line from a file.
//return true - has data
//		false - no data
//parameters:
//char arr[]: output array
//int max_array_size: max array can be read
//int number_read: the number of the char has been read
///////////////////////////////////////////////////////////
void readFromFile(array<System::Int32, 2>^ twoDArray, int& number_read)
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
		//bool flag = 
		findInfo(strRead, keyword, x, y, z, a);
		/*if (!flag)
			break;*/
		//cout << "X: " << x << "   Y: " << y << endl;

		//twoDArray[position, 0] = x;
		//twoDArray[position, 1] = y;

		position++;
	}

	instream.close();
	number_read = position;
	/*if (number_read == 0)
		return false;
	else
		return true;*/
}