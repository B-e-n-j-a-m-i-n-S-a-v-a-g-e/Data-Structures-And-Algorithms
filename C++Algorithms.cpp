#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

//TWO SUM 

//Given an array of integers, return the indices of the two numbers such that they add up to a specific target
//You may assume that each input  would have exactly one solution, and you may not use the same element twice.


//Example:
//
//Given nums = [2,7,11,15], target 9,
//
//Because nums[0] + nums[1] = 2 + 7 = 9,
//
//return [0,1].


//NAIVE SOLUTION O(N * N)

/*
int main()
{
	std::vector<int> vec = {2,7,11,15};
	std::vector<int> resultsVec;
	int target = 9;

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec.size(); j++)
		{
			if (vec[i] != vec[j])
			{
				if (vec[i] + vec[j] == target)
				{
					resultsVec.push_back(vec[i]);
					resultsVec.push_back(vec[j]);
				}
			}
		}
	}

	std::cout << resultsVec[0] << std::endl;
	std::cout << resultsVec[1] << std::endl;

	
    return 0;
}
*/

//OPTIMAL SOLUTION O(N LOG N)

int main()
{
	
	std::vector<int> vec = { 2,7,11,15 };
	std::vector<int> resultsVec;

	std::vector<std::pair<int, int>> vec2;
	int target = 26;

	for (int i = 0; i < vec.size(); i++)
	{
		std::pair <int, int> temp(vec[i], i);
		vec2.push_back(temp);
	}
	
	//Sort the array just in case
	std::sort(vec2.begin(), vec2.end());

	int i = 0;
	int j = vec2.size() - 1;

	while (i < j)
	{
		if (vec2[i].first + vec2[j].first == target)
		{
			resultsVec.push_back(vec2[i].first);
			resultsVec.push_back(vec2[j].first);

			std::cout << resultsVec[0] << std::endl;
			std::cout << resultsVec[1] << std::endl;
		}
		else if (vec2[i].first + vec2[j].first > target)
		{
			j--;
		}
		else 
		{
			i++;
		}
	}	

	return 0;
}
