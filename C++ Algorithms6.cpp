#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

//CONTAINS DUPLICATE

// Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that
// nums[i] == nums[j] and the absolute difference between i and j is at most k.

//NAIVE SOLUTION O(N * N)

/*
int main()
{

	std::vector<int> vec = {2,0,1,5,6,7,8,1};
	int k = 4;
	bool solution = false;

	for (int i = 0; i < vec.size(); i++)
	{
		int j = i - 1;

		while (j >= 0)
		{
			if (std::abs(j - i) > k)
			{
				break;
			}
			if (vec[i] == vec[j])
			{
				solution = true;
				std::cout << solution << std::endl;
			}
			j--;
		}
	}

	solution = false;

	std::cout << solution << std::endl;
	return 0;
}
*/

//OPTIMAL SOLUTION O(N)


int main()
{
	std::vector<int> vec = { 2,1,1,5,6,7,8,1 };
	int k = 4;
	std::unordered_map<int, int> hash;
	bool solution = false;

	for (int i = 0; i < vec.size(); i++)
	{
		if (hash.find(vec[i]) != hash.end())
		{
			if (i - hash[vec[i]] <= k)
			{
				solution = true;
				std::cout << solution << std::endl;
			}
			else
			{
				hash[vec[i]] = i;
			}
		}
		else
		{
			hash[vec[i]] = i;
		}
	}

	solution = false;
	std::cout << solution << std::endl;


return 0;
}
