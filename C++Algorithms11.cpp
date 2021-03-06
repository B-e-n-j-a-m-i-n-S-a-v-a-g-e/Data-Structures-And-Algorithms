#include "stdafx.h"
#include <iostream>


//SAME TREE

// Given two binary trees, write a function to determine whether they are the same or not.
// Two binary trees are considered to be the same if they are structurally identical and the nodes have the same value.

//		1           1
//	  /	  \		  /	  \
//	 2	   3	 2	   3

// [1,2,3],      [1,2,3]

// Output: true

//		1           1
//	  /	  		 	  \
//	 2	  	 			2

// [1,2,],      [1,null,2]

// Output: false

// SOLUTION USING RECURSION O(n) 

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	bool IsSameTree(TreeNode* p, TreeNode* q)
	{
		if (p == NULL && q == NULL) return true;
		if (p == NULL || q == NULL) return false;
		return p->val == q->val && IsSameTree(p->left, q->left) && IsSameTree(p->right, q->right);
	}
};

int main()
{
	return 0;
}