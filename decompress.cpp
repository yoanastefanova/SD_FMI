#include "pch.h"
#include <iostream>

#include "E:\ФМИ\СД\StackImplementation\StackImplementation\StackArray.hpp"

/*
Write a programm that "decompresses" a given string. The compressed string may contain 2 things:
 - Letters from A to Z that are decompressed to the same letter
 - A group which is a number N followed by another group in brackets which is decompressed to the group in the brackets N times.
 Examples: A -> A AB -> AB 3(A) -> AAA 3(AB2(B)) -> ABBBABBBABBB 12(ZQ) -> ZQZQZQZQZQZQZQZQZQZQZQZQ
*/

void decompress(char *expr)
{
	ArrStack<int> nums;
	ArrStack<char> letters;

	for (const char  *c = expr; *c; ++c)
	{
		if (*c > '0' && *c <= '9')
		{
			size_t num = 0;

			while (*c > '0' && *c <= '9')
			{
				num = num * 10 + (*c - '0');
				++c;
			}

			nums.push(num);
		}

		if (*c == ')')
		{
			ArrStack<char> toRepeat;
			size_t times = nums.top();
			nums.pop();

			while (letters.top() != '(')
			{
				toRepeat.push(letters.top());
				letters.pop();
			}

			letters.pop();

			ArrStack<char> helper = toRepeat;

			while (times > 1)
			{
				while (!toRepeat.empty())
				{
					letters.push(helper.top());
					helper.pop();
				}

				if (times != 1)
				{
					helper = toRepeat;
				}

				--times;
			}

			while (!toRepeat.empty())
			{
				letters.push(toRepeat.top());
				toRepeat.pop();
			}
		}

		else
		{
			letters.push(*c);	
		}		
	}

	letters.toString(expr);
}



int main()
{
	char expr1[20] = "3(A)";

	decompress(expr1);
	std::cout << expr1;


   return 0; 
}
