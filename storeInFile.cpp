#include "pch.h"
#include <fstream>
#include <iostream>


/*Въвеждаме студенти от стандартния вход в следния формат: име, ФН, оценка (всяко на отделен ред)
до край на входните данни. Въведените данни записваме във файл с име „students.txt”. */


void printFile(const char *name)
{
	std::ifstream in(name);

	if (in)
	{
		char line[256];

		while (in)
		{
			in.getline(line, 256);
			std::cout << line << '\n';
		}

		/*

		 //Използвайки файла “students.txt” с вече записаната информация от предната задача, прочитаме неговото
		 //съдържание и го извеждаме на стандартния изход.
		  

		unsigned facNum;
		char name[256];
		float grade;

		while (in >> name >> facNum >> grade)
		{
			std::cout << name << " " << facNum << " " << grade << '\n';
		}
		*/
	}

	else
	{
		std::cout << "Could not open file!\n";
	}
}


int main()
{
	std::ofstream out("students.txt");

	if (out)
	{
		char name[128]; // <=127 symbols
		int facNum;		
		float grade;

		while (std::cin >> name >> facNum >> grade)
		{
			out << name << facNum << grade << '\n';
		}
	}

	else
	{
		std::cout << "Could not open file!\n";
	}

	out.close();

	return 0;
}
