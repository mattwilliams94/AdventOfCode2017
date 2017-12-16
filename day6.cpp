#include "stdafx.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib> // for exit()

using namespace std;

int main()
{
	const int COLUMNS = 1;
	const int ROWS = 16;

	string data[COLUMNS];

	ifstream inputFile("day5input.txt");

	int values[ROWS];

	for (int j = 0; j < ROWS; ++j)
	{
		getline(inputFile, data[0], '\t');
		values[j] = atoi(data[0].c_str());
	}

	inputFile.close();

	int storageArray[10000][ROWS]{ 0 };
	int counter{ 0 };
	int matchValue = 0;

	for (int j = 0; j < ROWS; j++)
	{
		storageArray[counter][j] = values[j];
	}

	counter++;
	bool check{ true };
	int distance{ 0 };

	while (check)
	{
		int maxBankValue = values[0];
		int maxBankPosition = 0;

		// Find max
		for (int j = 0; j < ROWS; ++j)
		{
			if (values[j] > maxBankValue)
			{
				maxBankValue = values[j];
				maxBankPosition = j;
			}
		}

		// Collect from max
		values[maxBankPosition] = 0;
		maxBankPosition++;

		// Distribute
		while (maxBankValue > 0)
		{
			if (maxBankPosition > (ROWS - 1)) { maxBankPosition = 0; }

			values[maxBankPosition]++;
			maxBankValue--;
			maxBankPosition++;

		}

		// Store
		for (int j = 0; j < ROWS; j++)
		{
			storageArray[counter][j] = values[j];
		}

		// Check
		counter++;
		int checkCounter = 0;
		matchValue = 0;

		for (int i = 0; i < counter - 1; i++)
		{
			for (int j = 0; j < ROWS; j++)
			{
				if (values[j] == storageArray[i][j]) { matchValue++; }
				if (matchValue == ROWS)
				{
					distance = (counter - 1) - i;
					check = false;
				}
			}
			matchValue = 0;
		}

	}

	std::cout << "Repeat after " << counter - 1 << " redistributions.\nCycles between is " << distance << ".\n";
	return 0;
}
