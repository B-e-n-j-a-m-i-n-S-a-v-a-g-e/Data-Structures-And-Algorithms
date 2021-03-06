#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

//MAX PRODUCT OF THREE NUMBERS

//Given an integer array, find three numbers whose product is maximum and output the maximum product.

//Example 1:
//
//Input: [1,2,3]
//
//Output 6
//
//Example 2:
//
//Input: [1,2,3,4]
//
//Output 24
//
//Notes: - The length of the given array will be in the range [3, 10^4] and all elements are in the range [-1000,1000].
//		 - Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer. 


//EXTREMELY NAIVE SOLUTION O(N * N * N)
/*
int main()
{
	std::vector<int> vec = { 1,2,3,4};
	int maxValue = 0;

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = i + 1; j < vec.size(); j++)
		{
			for (int k = j + 1; k < vec.size(); k++)
			{
				int temp = vec[i] * vec[j] * vec[k];

				if (temp > maxValue)
				{
					maxValue = temp;
				}
			}
		}
	}

	std::cout << maxValue << std::endl;

	return 0;
}
*/

//IMPROVED SOLUTION O(N LOG N)

/*
int main()
{
	std::vector<int> vec = { -10,-9,-8,-1,-2,1,2,3,4 };

	sort(vec.begin(), vec.end());

	int sample1 = vec[vec.size() - 1] * vec[vec.size() - 2] * vec[vec.size() - 3];

	//In the case that there are negative integers in array
	//Cannot use first three integers, because the product of three negatives would be a negative.

	int sample2 = vec[0] * vec[1] * vec[vec.size() - 1];
	
	std::cout << std::max(sample1, sample2) << std::endl;

	return 0;
}
*/

//OPTIMAL SOLUTION O(N)

int main()
{

	int max1 = -1000, max2 = -1000, max3 = -1000, min1 = 1000, min2 = 1000;
	std::vector<int> vec = { -15,4,2,10,11,0,-3,6,12};

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] >= max3)
		{
			max1 = max2;
			max2 = max3;
			max3 = vec[i];
		}
		else if (vec[i] >= max2) 
		{
			max1 = max2;
			max2 = vec[i];
		}
		else if (vec[i] >= max1)
		{
			max1 = vec[i];
		}

		if (vec[i] <= min1)
		{
			min2 = min1;
			min1 = vec[i];
		}
		else if (vec[i] <= min2)
		{
			min2 = vec[i];
		}
	}

	int sample1 = max1 * max2 * max3;

	//In the case that there are negative integers in array.
	//Cannot use first three integers, because the product of three negatives would be a negative.

	int sample2 = max3 * min1 * min2;

	std::cout << std::max(sample1, sample2) << std::endl;

	return 0;
}
