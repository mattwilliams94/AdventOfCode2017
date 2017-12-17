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
	const int COLUMNS	{  20 };
	const int ROWS		{ 512 };

	ifstream	inputFile("day4input.txt");
	string		data	[COLUMNS];
	string		input	[ROWS][COLUMNS];

	int rowCount { 0 };
	int colCount { 0 };

	for (int j = 0; j < ROWS; ++j)
	{
		getline(inputFile, data[0], '\n');
		data[0].append(" ");

		std::string delimiter	{ " " };
		size_t		pos			{ 0 };

		while ((pos = data[0].find(delimiter)) != std::string::npos)
		{
			input[rowCount][colCount] = data[0].substr(0, pos);
			data[0].erase(0, pos + delimiter.length());
			colCount++;
		}

		colCount = 0;
		rowCount++;
	}

	inputFile.close();

	int rows		{ 0 };
	int cols		{ 0 };
	int checkIndex	{ 0 };
	int copies		{ 0 };
	int valid		{ 0 };

	string sample;
	string check;

	while (rows < ROWS)
	{
		sample = input[rows][cols];
		check  = input[rows][checkIndex];

		std::sort(sample.begin(), sample.end());
		std::sort(check.begin(), check.end());

		// column check complete
		if (check == "")
		{
			checkIndex = -1;	// as it'll be iterated at the end of the loop
			cols++;
		}

		// line check complete
		if (sample == "")
		{
			cols = 0;
			rows++;
		}

		if ((sample == check) & (checkIndex != cols))
		{
			copies++;
			rows++;
			checkIndex = -1;	// as it'll be iterated at the end of the loop
			cols = 0;
		}

		checkIndex++;
	}

	std::cout << "There are " << ROWS - (copies) << " valid passphrases.\n";

}