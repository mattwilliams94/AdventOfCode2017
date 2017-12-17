#include "stdafx.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>		// for exit()

using namespace std;

int main()
{
	// input properties
	const int COLUMNS	{ 1 };
	const int ROWS		{ 1043 };

	string data[COLUMNS];

	ifstream inputFile("day4input.txt");

	int input[ROWS];

	for (int j = 0; j < ROWS; ++j)
	{
		getline(inputFile, data[0], '\n');
		input[j] = atoi(data[0].c_str());
	}

	inputFile.close();

	int position	{ 0 };
	int currentValue{ 0 };
	int steps		{ 0 };

	while (1)
	{
		currentValue = input[position];
		
		if (currentValue > 2)
		{
			input[position]--;
		}
		else
		{
			input[position]++;
		}

		position	+= currentValue;

		steps++;

		if (position >= ROWS) { break; }
	}

	std::cout << "It took " << steps << " to exit the stack.\n";

}