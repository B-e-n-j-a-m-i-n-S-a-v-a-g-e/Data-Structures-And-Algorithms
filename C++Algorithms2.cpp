#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

//MAX CONSECUTIVE ONES

//Given a binary array, find the maximum number of consecutive 1s in this array

//Example:
//
//Input: [1,1,0,1,1,1]
//
//Output 3
//
//Explanation: The first two digitsor the last three digits are consecutive 1s.
//The maximum number of consecutive 1s is 3.
//
//Notes: - The input array will only contain 0 and 1.
//		- The length of input array is a positive integer and will not exceed 10,000.


//NAIVE SOLUTION O(N * N)

/*
int main()
{
	std::vector<int> vec = { 1,1,0,1,1,1 };
	int maxLength = 0;

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] != 0)
		{
			int currentLength = 1;
			int next = i + 1;

			while (next < vec.size() && vec[next] == 1)
			{
				currentLength++;
				next++;
			}
			maxLength = std::max(maxLength, currentLength);
		}
	}

	std::cout << maxLength << std::endl;


return 0;
}
*/

//OPTIMAL SOLUTION O(N)


int main()
{
	std::vector<int> vec = { 1,1,0,1,1,1 };
	int maxLength = 0;
	int i = 0;

	while(i < vec.size()) 
	{
		if (vec[i] == 1)
		{
			int currentLength = 1;
			int next = i + 1;
			while (next < vec.size() && vec[next] == 1)
			{
				next++;
				currentLength++;
			}
			i = next;
			maxLength = std::max(maxLength, currentLength);
		}
		else
		{
			i++;
		}
	}

	std::cout << maxLength << std::endl;
	
return 0;
}
