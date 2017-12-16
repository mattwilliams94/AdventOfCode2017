#include "stdafx.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for exit()

int main()
{
	int array[500][500]{ 0 };

	int target;
	std::cout << "What's your target value?: ";
	std::cin >> target;

	int layer = 1;
	int x = 0;
	int y = 0;

	int centre = 250;
	int currentR = 0;
	int currentC = 0;

	array[centre][centre] = 1;

	while (layer < 5)
	{
		for (int y = 0; y < (layer+1) ; y++)
		{
			int x = layer;
			currentR = centre - y;
			currentC = centre + x;

			array[currentR][currentC] = array[currentR - 1][currentC - 1] + array[currentR - 1][currentC] + array[currentR - 1][currentC + 1]
									  + array[currentR	  ][currentC - 1]								  + array[currentR	  ][currentC + 1]
									  + array[currentR + 1][currentC - 1] + array[currentR + 1][currentC] + array[currentR + 1][currentC + 1];

			if (array[currentR][currentC] > target) 
			{ 
				std::cout << "The first value to exceed " << target << " is " << array[currentR][currentC] << "\n"; 
				return 0;
			}

		}

		for (int x = (layer + 1)-2; x > -(layer+1); x--)
		{
			int y = layer;
			currentR = centre - y;
			currentC = centre + x;

			array[currentR][currentC] = array[currentR - 1][currentC - 1] + array[currentR - 1][currentC] + array[currentR - 1][currentC + 1]
				+ array[currentR][currentC - 1] + array[currentR][currentC + 1]
				+ array[currentR + 1][currentC - 1] + array[currentR + 1][currentC] + array[currentR + 1][currentC + 1];

			if (array[currentR][currentC] > target)
			{
				std::cout << "The first value to exceed " << target << " is " << array[currentR][currentC] << "\n";
				return 0;
			}
		}

		for (int y = -(layer+1)+2; y < (layer+1); y++)
		{
			int x = layer;
			currentR = centre + y;
			currentC = centre - x;

			array[currentR][currentC] = array[currentR - 1][currentC - 1] + array[currentR - 1][currentC] + array[currentR - 1][currentC + 1]
				+ array[currentR][currentC - 1] + array[currentR][currentC + 1]
				+ array[currentR + 1][currentC - 1] + array[currentR + 1][currentC] + array[currentR + 1][currentC + 1];

			if (array[currentR][currentC] > target)
			{
				std::cout << "The first value to exceed " << target << " is " << array[currentR][currentC] << "\n";
				return 0;
			}
		}

		for (int x = (layer+1)-2; x > -(layer+1) - 1; x--)
		{
			int y = layer;
			currentR = centre + y;
			currentC = centre - x;

			array[currentR][currentC] = array[currentR - 1][currentC - 1] + array[currentR - 1][currentC] + array[currentR - 1][currentC + 1]
				+ array[currentR][currentC - 1] + array[currentR][currentC + 1]
				+ array[currentR + 1][currentC - 1] + array[currentR + 1][currentC] + array[currentR + 1][currentC + 1];

			if (array[currentR][currentC] > target)
			{
				std::cout << "The first value to exceed " << target << " is " << array[currentR][currentC] << "\n";
				return 0;
			}
		}

		for (int y = (layer + 1) - 2; y > 0 ; y--)
		{
			int x = layer;
			currentR = centre + y;
			currentC = centre + x + 1;

			array[currentR][currentC] = array[currentR - 1][currentC - 1] + array[currentR - 1][currentC] + array[currentR - 1][currentC + 1]
				+ array[currentR][currentC - 1] + array[currentR][currentC + 1]
				+ array[currentR + 1][currentC - 1] + array[currentR + 1][currentC] + array[currentR + 1][currentC + 1];

			if (array[currentR][currentC] > target)
			{
				std::cout << "The first value to exceed " << target << " is " << array[currentR][currentC] << "\n";
				return 0;
			}
		}

		++layer;
	}
}
