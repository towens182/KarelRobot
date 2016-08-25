#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Beeper.h"
#include "MyForm.h"


//Get info from specifics.txt
void findInfo(std::string my_string, std::string& keyword, int& X, int& Y, int& Z, int& A)
{
	using namespace std;
	string x[5];
	int index = 0;
	string::iterator my_iter;
	for (my_iter = my_string.begin(); my_iter != my_string.end(); my_iter++)
	{
		if (*my_iter != ' ') {
			char temp = *my_iter;
			x[index] = x[index] + *my_iter;
		}
		else
			index++;
		if (index > 4)
			break;
	}

	keyword = x[0];
	X = std::stoi(x[1]);
	Y = std::stoi(x[2]);
	Z = std::stoi(x[3]);
	A = std::stoi(x[4]);
}

void readFromFile(array <System::String^>^ keywordArray, array <System::Int32, 2>^ twoDArray, int& number_read)
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
		
		getline(instream, strRead); //reading one character from file to array

		int x, y, z, a;
		findInfo(strRead, keyword, x, y, z, a);
		System::String^ str3 = gcnew System::String(keyword.c_str());
		keywordArray[position] = str3;
		twoDArray[position, 0] = x;
		twoDArray[position, 1] = y;
		twoDArray[position, 2] = z;
		twoDArray[position, 3] = a;

		position++;
	}

	instream.close();
	number_read = position;
}