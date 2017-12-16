#include "stdafx.h"
#include <string>
#include <iostream>

int main()
{
	while (1)
	{
		std::cout << "Input: ";
		std::string input;
		std::cin >> input;

		int sum{ 0 };

		for (int ii = 0; ii < input.size()/2; ++ii)
		{
			if (input[ii] == input[ii + input.size()/2])
			{
				sum += (int)(input[ii] - '0');
			}
		}

		for (int ii = input.size()/2; ii < input.size(); ++ii)
		{
			if (input[ii] == input[ii - input.size() / 2])
			{
				sum += (int)(input[ii] - '0');
			}
		}

		std::cout << sum << "\n";
	}

    return 0;
}

