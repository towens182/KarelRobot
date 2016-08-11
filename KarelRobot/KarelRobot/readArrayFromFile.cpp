#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace System;


///////////////////////////////////////////////////////////
//Function: Find out the x and y from a string
//return true - has X and Y 
//		false - no data
//parameters:
//string - has X and Y coordinates
///////////////////////////////////////////////////////////
bool findCoordinates(std::string my_string, int& X, int& Y)
{
	using namespace std;
	string x[2];
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

	X = std::stoi(x[0]);
	Y = std::stoi(x[1]);

	return true;
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
bool readStringArrayFromFile(array<System::Int32, 2>^ twoDArray, int& number_read)
{
	using namespace std;

	ifstream instream;
	ofstream outstream;
	const string INPUTFILENAME = "specifics.txt";
	instream.open(INPUTFILENAME);

	string strRead;
	int position = 0; //this will be used incremently to fill characters in the array 
	using namespace std;
	while (!instream.eof())
	{
		//instream.get(array[position]); //reading one character from file to array
		getline(instream, strRead); //reading one character from file to array

		int x, y;
		bool flag = findCoordinates(strRead, x, y);
		if (!flag)
			break;
		//cout << "X: " << x << "   Y: " << y << endl;

		twoDArray[position, 0] = x;
		twoDArray[position, 1] = y;

		position++;
	}

	instream.close();
	number_read = position;
	if (number_read == 0)
		return false;
	else
		return true;
}

