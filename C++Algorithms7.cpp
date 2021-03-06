#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>

//VALID ANAGRAM

// Given two strings s and t,  write a function to determine if t is an anagram of s.
//
// For example: 
// s = "anagram", t = "nagaram", return true.
// s = "rat", t = "cat", return false.

//Note: You may assume that the string contains only lowercase characters.

// NAIVE SOLUTION O(n * n)
/*
int main()
{
	std::string s = "anagram";
	std::string t = "nagaram";
	bool result = false;

	if (s.size() != t.size())
	{
		result = false;
		std::cout << result << std::endl;
	}
	if (s == "" && t == "")
	{
		result = true;
		std::cout << result << std::endl;
	}

	std::vector<bool> matched(t.size(), false);

	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < t.size(); j++)
		{
			if (t[j] == s[i] && !matched[j])
			{
				matched[j] = true;
				break;
			}
		}
	}

	for (int i = 0; i < matched.size(); i++)
	{
		if (!matched[i])
		{
			result = false;
			std::cout << result << std::endl;
		}
	}

	result = true;
	std::cout << result << std::endl;

	return 0;
}
*/


// IMPROVED SOLUTION O(n log n)
/*
int main()
{
	std::string s = "anagram";
	std::string t = "nagaram";
	bool result = false;

	if (s.size() != t.size())
	{
		result = false;
	}
	std::sort(s.begin(), s.end());
	std::sort(t.begin(), t.end());

	if (s == t)
	{
		result = true;
	}
	else
	{
		result = false;
	}

	std::cout << result << std::endl;

	return 0;
}
*/

// OPTIMAL SOLUTION O(n)

int main()
{
	std::string s = "anagram";
	std::string t = "nagaram";
	bool result;
	
	/*
	//SOLUTION USING HASHMAP

	std::unordered_map<char, int> H;

	for (int i = 0; i < s.size(); i++)
	{
		H[s[i]]++;
	}
	for (int j = 0; j < t.size(); j++)
	{
		H[t[j]]--;
	}
	for (auto elem : H)
	{
		if (elem.second != 0)
		{
			result = false;
		}
		else
		{
			result = true;
		}
	}
	*/

	//SOLUTION USING VECTOR

	std::vector<int> H(128, 0);

	for (int i = 0; i < s.size(); i++)
	{
		H[s[i]]++;
	}
	for (int i = 0; i < t.size(); i++)
	{
		H[t[i]]--;
	}
	for (int i = 0; i < 128; i++)
	{
		if (H[i] != 0)
		{
			result = false;
		}
		else
		{
			result = true;
		}
	}

	std::cout << result << std::endl;

	return 0;
}

