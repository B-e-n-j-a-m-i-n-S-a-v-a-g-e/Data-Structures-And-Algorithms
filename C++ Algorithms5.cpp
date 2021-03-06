#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <stack>

//BASEBALL

//Given a list of strings, each strign can be one of the following types:

// Integer (one round's score): Directly represents the number of points you get in this round.
// "+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points
// "O" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
// "C" (an operation which isn't a round's score): Represents the last valid round's points you get were invalid and should bve removed.

//Each round's operation is permanent and could have an impact on the round before and the round after.

//You need to return the sum of the points you could get in all the rounds.

//Example:

// Input: ["5","2","C","D","+"]
// Output: 30
// Explanation: 
// Round 1 You could get 5 points. The sum is 5.
// Round 2 You could get  2 points. The sum is 7.
// Operation 1: The round 2's data was invalid. The sum is: 5.
// Round 3: You could get 10 points (the round 2's data has been removed). The sum is: 15.
// Round 4: You could get 5 + 10 = 15 points. The sum is 30.

//Note: 

// The size of the input list will be between 1 and 1000.
// Every integer represented in the list will be between -30000 and 30000.

//NAIVE SOLUTION O(N * N)

	
	int main()
	{

		std::vector<std::string> vec = { "5","2","C","D","+" };

		if (vec.size() == 0)
		{
			return 0;
		}

		std::vector<bool> cancel(vec.size(), false);


		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i] == "C")
			{
				int j = i - 1;
				while (j >= 0 )
				{
					if (!cancel[j])
					{
						cancel[j] = true;
						break;
					}
					j--;
				}
				cancel[i] = true;
			}
			else if (vec[i] == "D")
			{
				int j = i - 1;

				while (j >= 0)
				{
					if (!cancel[j])
					{
						vec[i] = std::to_string(2 * stoi(vec[j]));
						break;
					}
					j--;
				}

			}
			else if (vec[i] == "+")
			{
				int j = i - 1;
				int count = 0;
				int sum = 0;
				
				while (j >= 0)
				{
					if (count == 2)
					{
						break;
					}
					if (!cancel[j])
					{
						sum = sum + stoi(vec[j]);
						count++;
					}
					j--;
					vec[i] = std::to_string(sum);
				}

			}
			else
			{
				//Do nothing
			}
		}
		int sum = 0;
		for (int i = 0; i < vec.size(); i++)
		{
			if (!cancel[i])
			{
				sum += stoi(vec[i]);
			}
		}

		std::cout << sum << std::endl;

		return 0;
	}

	


//OPTIMAL SOLUTION O(N)
 
/*
int main()
{

	std::vector<std::string> vec = { "5","2","C","D","+" };
std::vector<bool> cancel(vec.size(), false);

	if (vec.size() == 0)
	{
		return 0;
	}

	std::stack <int> s;

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == "C")
		{
			s.pop();
		}
		else if (vec[i] == "D")
		{
			s.push(2 * s.top());
		}
		else if (vec[i] == "+")
		{
			int x = s.top();
			s.pop();
			int y = s.top();
			s.push(x);
			s.push(x + y);
		}
		else {
			s.push(stoi(vec[i]));
		}
	}

	int sum = 0;

	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}
	
	std::cout << sum << std::endl;

	return 0;
}

*/