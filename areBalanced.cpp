#include "pch.h"
#include <fstream>
#include <iostream>

#include "E:\ФМИ\СД\StackImplementation\StackImplementation\Stack.hpp"

/*
Write a program which reads from a file a string of brakets, i.e. '(', ')', '[', ']', '{', '}'. 
The program returns a True if the brakets are balanced and False, otherwise.
*/

bool areBalanced(const char *_name)
{
	Stack<char> s1;

	std::ifstream in(_name);
	

	if (!in)
	{
		std::cout << "Could not open file!\n";
		return false;
	}

	while (in)
	{
		char c;

		in.read(&c, 1);

		if (in)
		{
			switch (c)
			{
			case '(':
			{
				s1.push(c);
				break;
			}

			case ')':
			{
				if (s1.empty() || s1.top() != '(')
				{
					in.close();
					return false;
				}

				s1.pop();
				break;
			}

			case '[':
			{
				s1.push(c);
				break;
			}

			case ']':
			{
				if (s1.empty() || s1.top() != '[')
				{
					in.close();
					return false;
				}

				s1.pop();
				break;
			}


			case '{':
			{
				s1.push(c);
				break;
			}

			case '}':
			{
				if (s1.empty() || s1.top() != '{')
				{
					in.close();
					return false;
				}

				s1.pop();
				break;
			}
			}
		}
	}

	in.close();

	if (!s1.empty())
	{
		return false;
	}

	return true;
}


int main()
{
	
	const char* path = "E:\\ФМИ\\СД\\STACK\\areBalanced\\path.txt";

	std::cout << "The parenthesis in the text file are balanced.\n" << std::boolalpha << areBalanced(path) << '\n';
	

	return 0; 
}

