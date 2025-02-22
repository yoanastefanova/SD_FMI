// task01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "E:\ФМИ\СД\StackImplementation\StackImplementation\Stack.hpp"


//Evaluate a mathematical expression written in reverse polish notation.

bool isOp(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

int evaluate(const char* expr)
{
	Stack<int> nums;
	Stack<char> ops;

	for (const char* c = expr; *c; ++c)
	{
		if (isDigit(*c))
		{
			int num = 0;

			while (isDigit(*c))
			{
				num = (*c - '0');
				nums.push(num);
				//num = num * 10 + (*c - '0');//за да взима цялото число, ако е с повече от една цифра
				++c;
			}

			//nums.push(num);
		}

		if (isOp(*c))
		{
			int b = nums.top();
			nums.pop();
			int a = nums.top();
			nums.pop();

			switch (*c)
			{
			case '+':
			{
				nums.push(a + b);
				break;
			}

			case '-':
			{
				nums.push(a - b);
				break;
			}

			case '*':
			{
				nums.push(a * b);
				break;
			}

			case '/':
			{
				if (b == 0)
				{
					std::cout << "Illegal division! You cannot divide by 0!\n";
					return 0;
				}

				else
				{
					nums.push(a / b);
				}			
			}		
			}
		}
	}

	int result = nums.top();
	nums.pop();
	return result;
}


int main()
{
	const char expr[] = "1192*+";

	std::cout << evaluate(expr) << '\n';

   return 0; 
}

