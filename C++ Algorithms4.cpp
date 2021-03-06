#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <stack>

//VALID PARENTHESES

//Given a string containing just the characters '(', ')', '{','}', and '[',']', determine if the input string is valid.
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.


//INCORRECT APPROACH

/*
int main()
{
	std::vector<char> vec = { '(','(','(', ')',')',')' };
	int counter = 0;
	bool isEven = false;
	
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == '(')
		{
			counter++;
		} 
		else if (vec[i] == ')')
		{
			counter--;
		}
	}

	if (counter == 0)
	{
		isEven = true;
	}

	std::cout << isEven << std::endl;


return 0;
}
*/

//IMPROVED RRECURSIVE SOLUTION O(N * N)

/*
bool check(std::string str) {
	if (str.size() == 0)
	{
		return true;
	}
	if (str.find("()") != std::string::npos)
	{
		int index = str.find("()");
		str.replace(index, 2, "");
		return check(str);
	}
	else if (str.find("{}") != std::string::npos)
	{
		int index = str.find("{}");
		str.replace(index, 2, "");
		return check(str);
	}
	else if (str.find("[]") != std::string::npos)
	{
		int index = str.find("[]");
		str.replace(index, 2, "");
		return check(str);
	}
	else
	{
		return false;
	}
}

int main()
{
	std::string test = "((()))";
	std::cout << check(test) << std::endl;

return 0;
}

*/


//OPTIMAL SOLUTION O(N)

bool check(std::string str)
{
	std::stack<char> st;

	if (str.size() == 0)
	{
		return true;
	}

	if (str.size() == 1)
	{
		return false;
	}

	if (str[0] == ')' || str[0] == '}' || str[0] == ']')
	{
		return false;
	}
	else
	{
		st.push(str[0]);
	}

	for (int i = 1; i < str.size(); i++)
	{
		if (str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			if (st.empty())
			{
				return false;
			}
			else
			{
				if (st.top() == '{' && str[i] == '}' || st.top() == '(' && str[i] == ')' || st.top() == '[' && str[i] == ']')
				{
					st.pop();
				}
				else
				{
					return false;
				}
			}
		}
		else
		{
			st.push(str[i]);
		}

	}

	if (st.empty())
	{
		return true;
	}
	else
	{
		return false;
	}

}

int main()
{
	std::string test = "((()))";
	std::cout << check(test) << std::endl;
	return 0;
}
