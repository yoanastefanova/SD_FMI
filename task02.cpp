#include "pch.h"
#include <fstream>
#include <iostream>
/*
Task2: Напишете функция, която:

-чете от файл и съставя число, образувано от всички цифри в реда на тяхното срещане;
-чете от файл, в който на всеки ред се срещат име и число, и извежда това име, срещу което стои най-голямо число;
*/

// Read from a file ---> make a number from all the digits in the file (in the order they are found)


double makeNum(const char *_name)
{
	double num = 0;

	std::ifstream in(_name);

	if (in)
	{
		char cur;

		while (in)
		{
			in.read(&cur, 1);

			if (in)
			{
				if (cur >= '0' && cur <= '9')
				{
					int temp = cur - '0'; // char->double
					num = num * 10 + (double) temp;
				}
			}
		}

		in.close();

		return num;
	}

	std::cout << "Could not open file!/n";

	return 0;
}


// Read from a file, which, on each row, has a name and a number ---> print the name, which has the highest number on its right


size_t maxIndex(const unsigned *arr, const size_t &size)
{
	unsigned maxIndex = 0;

	for (size_t j = 1; j < size; j++)
	{
		if (arr[maxIndex] < arr[j])
		{
			maxIndex = j;
		}
	}

	return maxIndex;
}

void findName(const char* _name)
{
	std::ifstream in(_name);

	if (in)
	{
		unsigned number[2048] = { 0 };
		size_t rows = 0;

		char current;

		while (in)
		{
			in.read(&current, 1);

			if (current >= '0' && current <= '9')
			{
				do
				{
					number[rows] = number[rows] * 10 + (current - '0');
					in.read(&current, 1);
					if (in && current == '\n')
					{
						++rows;
					}
				} while (current >= '0' && current <= '9' && in);
			}
			else if (current == '\n')
			{
				++rows;
			}
		}

		size_t maxRow = maxIndex(number, rows + 1);

		in.close(); // Move to the beginning from the current position.
		in.open(_name);

		unsigned curRow = 0; // Move to the row which has the maximum number in it.

		while (curRow != maxRow)
		{
			in.read(&current, 1);

			if (in)
			{
				if (current == '\n')
				{
					++curRow;
				}
			}
		}

		while (in)
		{
			in.read(&current, 1); // Start looking for the name - a word with a capital letter.

			if (in)
			{
				if (current >= 'A' && current <= 'Z')
				{
					do
					{
						std::cout << current;
						in.read(&current, 1);
					} while (in && current >= 'a' && current <= 'z');
				}
				else if (current == '\n')
				{
					in.close();
					return;
				}
			}
		}

		in.close();
		return;
	}

	std::cout << "\n\tCould not open file.txt!";

}

int main()
{
    return 0; 
}
