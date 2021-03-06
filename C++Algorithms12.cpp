#include "stdafx.h"
#include <iostream>
#include <algorithm>


//MAXIMUM DEPTH OF BINARY TREE

// Given a binary tree, find its maximum depth.
// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.


// OPTIMAL SOLUTION O(n) 

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	int MaxDepth(TreeNode* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		int l = MaxDepth(root->left);
		int r = MaxDepth(root->right);
		return std::max(l, r) + 1;
	}
};

int main()
{
	return 0;
}