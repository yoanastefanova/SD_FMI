#include "pch.h"
#include <fstream>
#include <iostream>


/*
Напишете функция, която заменя всички срещания на дадена дума във файл, със звездички.
*/

const int MAX_SIZE = 27000;
const int WORD_SIZE = 30;

bool isLetter(const char &c)
{
	return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
}


bool are_equal(const char* rhs, const char* lhs, const size_t& size)
{
	for (size_t i = 0; lhs[i]; i++)
	{
		if (rhs[i] != lhs[i])
		{
			return false;
		}
	}

	return true;
}

void format_buffer(char* buffer, const size_t& size, const char* word)
{
	for (size_t i = 0; i < size; i++)
	{
		if (isLetter(buffer[i]))
		{
			char next_letters[WORD_SIZE] = { '0' };
			size_t j = 0;
			size_t current_i = i;

			do
			{
				next_letters[j] = buffer[current_i];
				++current_i;
				++j;
			} while (isLetter(buffer[current_i]));

			if (are_equal(next_letters, word, j))
			{
				for (size_t k = 0; k < j; ++k, ++i)
				{
					buffer[i] = '*';
				}
			}
		}
	}
}

void censure(const char* path, const char* word)
{
	std::ifstream fin(path);

	if (fin)
	{
		char buffer[MAX_SIZE] = { '0' };
		char current;
		size_t size = 0;

		while (fin)
		{
			fin.read(&current, 1);

			if (fin)
			{
				buffer[size] = current;
				++size;
			}
		}

		fin.close();

		format_buffer(buffer, size, word);

		std::ofstream fout(path, std::ios::trunc);

		for (size_t i = 0; i < size; i++)
		{
			fout << buffer[i];
		}
	}
	else
	{
		std::cout << "\n\tCould not open file!" << std::endl;
	}
}

int main()
{
	const char* path = "file.txt";

	char word[WORD_SIZE];

	std::cout << "Enter word: ";
	std::cin >> word;

	censure(path, word);

   return 0; 
}

