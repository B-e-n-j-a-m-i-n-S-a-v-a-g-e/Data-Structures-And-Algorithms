#include "stdafx.h"
#include <iostream>


//INVERT BINARY TREE

// Invert a binary tree
//		4
//	  /	  \
//	 2	   7
//  / \   / \
//  1  3  6  9
//
// to
//		4
//	  /	  \
//	 7	   2
//  / \   / \
//  9  6  3  1
//

// SOLUTION O(n) 

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	TreeNode* invertTree(TreeNode* root) 
	{
		if (root == NULL)
		{
			return NULL;
		}
		TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;
		invertTree(root->left);
		invertTree(root->right);
		return root;

	}
};

int main()
{
	return 0;
}

