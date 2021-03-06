#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <utility>

//FIND K PAIRS WITH SMALLEST SUMS

// You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
// Define a pair (u,v) which consists of one element from the first array and one element from the second array.
// Find the pairs (u1,v1),(u2,v2)...(uk,vk) with the smallest sums.

// Example 1: 
// Given nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// Return [1,2],[1,4],[1,6]
// The first 3 pairs are returned from the sequence:
// [1,2], [1,4], [1,6], [7,2], [7,4], [11,2], [7,6], [11,4], [11,6]

// Example 2: 
// Given nums1 = [1,1,2], nums2 = [1,2,3], k = 2
// Return [1,1],[1,1]
// The first 3 pairs are returned from the sequence:
// [1,1], [1,1], [1,2], [2,1], [1,2], [2,2], [1,3], [1,3], [2,3]


//INITIAL SOLUTION O(n * n log n) 
/*

class MyComparison {

public:
	bool operator() (const std::pair<int, int>& lhs, const std::pair<int, int>&rhs)
	{
		return lhs.first + lhs.second < rhs.first + rhs.second;
	}
};

class Solution {

public:
	std::vector<std::pair<int, int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k)
	{
		int m = nums1.size();
		int n = nums2.size();

		if (m * n == 0)
		{
			return std::vector<std::pair<int, int>>();
		}

		std::vector<std::pair<int, int>> all_pairs;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				all_pairs.push_back(std::make_pair(nums1[i], nums2[j]));
			}
		}

		std::sort(all_pairs.begin(), all_pairs.end(), MyComparison());
		return std::vector<std::pair<int, int>>(all_pairs.begin(), all_pairs.begin() + std::min(k, (int)(all_pairs.size())));

	}
};

int main()
{

	std::vector<int> nums1 { 1,7,11 };
	std::vector<int> nums2{ 2,4,6 };
	int k = 3;
	Solution s;

	std::vector<std::pair<int, int>> smallestPairs;
	smallestPairs = s.kSmallestPairs(nums1, nums2, k);

	return 0;
}

*/

//OPTIMIZED SOLUTION O(n * n log k) 

class MyComparison {

	bool min_queue;

public:
	MyComparison(const bool& min_q = false)
	{
		min_queue = min_q;
	}
	bool operator() (const std::pair<int, int>& lhs, const std::pair<int, int>&rhs)
	const {
		if (min_queue)
		{
			return (lhs.first + lhs.second > rhs.first + rhs.second);
		}
		else {
			return (lhs.first + lhs.second < rhs.first + rhs.second);
		}
	};

};

class Solution {

public:
	std::vector<std::pair<int, int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k)
	{
		std::priority_queue< std::pair<int, int>, std::vector<std::pair<int, int>>, MyComparison > q;

		for (int i = 0; i < nums1.size(); i++)
		{
			for (int j = 0; j < nums2.size(); j++)
			{
				if (q.size() < k)
				{
					q.push(std::make_pair(nums1[i], nums2[j]));
				}
				else
				{
					auto top_pair = q.top();
					if (top_pair.first + top_pair.second > nums1[i] + nums2[j])
					{
						q.pop();
						q.push(std::make_pair(nums1[i], nums2[j]));
					}
				}
			}
		}


		if (q.size() == 0)
		{
			return std::vector<std::pair<int, int>>();
		}

		std::vector<std::pair<int, int>> returns(q.size());
		int i = q.size() - 1;
		while (!q.empty())
		{
			returns[i] = q.top();
			q.pop();
			i--;
		}
		return returns;
	}
};

int main()
{

	std::vector<int> nums1{ 1,7,11 };
	std::vector<int> nums2{ 2,4,6 };
	int k = 3;
	Solution s;

	std::vector<std::pair<int, int>> smallestPairs;
	smallestPairs = s.kSmallestPairs(nums1, nums2, k);

	return 0;
}
