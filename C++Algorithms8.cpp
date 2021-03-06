#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

//KTH LARGEST ELEMENT IN AN ARRAY

// Find the kth largest element in an unsorted array. Note that it is the kth largest in the sorted order, not the kth distinct element.
//
// For example: 
// Given [3,2,1,5,6,4] and k = 2, return 5;

//Note: You may assume k is always valid, 1 <= k <= the array's length.

// NAIVE SOLUTION O(n log n)

/*
int main()
{

	std::vector<int> nums{ 3,2,1,5,6,4 };
	int k = 2;
	int solution;

	std::sort(nums.begin(), nums.end());

	solution = nums[nums.size() - k];

	std::cout << solution << std::endl;

	return 0;
}
*/

// OPTIMAL SOLUTION O(n log k)
int main()
{

	std::vector<int> nums{ 3,2,1,5,6,4 };
	int k = 2;
	int solution;

	std::priority_queue <int, std::vector<int>, std::greater<int>> pq;

	for (int i = 0; i < nums.size(); i++)
	{
		if (pq.size() < k)
		{
			pq.push(nums[i]);
		}
		else
		{
			int min_elem = pq.top();
			if (min_elem < nums[i])
			{
				pq.pop();
				pq.push(nums[i]);
			}
		}
	}

	solution = pq.top();

	std::cout << solution << std::endl;

	return 0;
}