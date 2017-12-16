#include "stdafx.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for exit()

int main()
{
	using namespace std;

	const int COLUMNS	= 16;
	const int ROWS		= 16;

	string data[COLUMNS];

	ifstream inputFile("day2input.txt");

	string values[ROWS][COLUMNS];

	for (int j = 0; j < ROWS; ++j)
	{
		for (int i = 0; i < COLUMNS-1; ++i)
		{
			getline(inputFile, data[i], '\t');
			values[j][i] = data[i];
		}
		getline(inputFile, data[15], '\n');
		values[j][15] = data[15];
	}

	inputFile.close();

	int checkSum = 0;

	for (int j = 0; j < ROWS; ++j)
	{
		int lowestVal { std::atoi(values[j][0].c_str()) };
		int highestVal{ std::atoi(values[j][0].c_str()) };

		for (int i = 0; i < COLUMNS; ++i)
		{
			if (std::atoi(values[j][i].c_str()) < lowestVal) { lowestVal = std::atoi(values[j][i].c_str()); }
			if (std::atoi(values[j][i].c_str()) > highestVal) { highestVal = std::atoi(values[j][i].c_str()); }
		}

		std::cout << highestVal << "\t" << lowestVal << "\t" << (std::atoi(values[j][15].c_str())) << "\n";

		checkSum += (highestVal - lowestVal);
	}

	std::cout << "\n" << checkSum << "\n";

	int divDiff = 0;

	double val;

	for (int j = 0; j < ROWS; ++j)
	{
		int numerator	= 0;
		int denominator = 0;

		for (int i = 0; i < COLUMNS; ++i)
		{
			for (int k = 0; k < COLUMNS; ++k)
			{
				double num = std::atoi(values[j][i].c_str());
				double den = std::atoi(values[j][k].c_str());
				
				val = fmod(num, den);

				if ((val == 0) && num != den)
				{
					std::cout << std::atoi(values[j][i].c_str()) << "\t" << std::atoi(values[j][k].c_str()) << "\n";
					numerator	= std::atoi(values[j][i].c_str());
					denominator = std::atoi(values[j][k].c_str());
				}
			}
		}

		divDiff += numerator / denominator;
	}

	std::cout << "\n" << divDiff << "\n";

	return 0;
}
