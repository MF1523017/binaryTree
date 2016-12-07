#include"tree.h"
#include<iostream>
#include<vector>
//Given a binary tree, find its minimum depth
//The minimum depth is the number of nodes
//along the shortest path from the root node down
//to the nearest leaf node.

using std::vector;
class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;
		else
		{
			if (root->Left == nullptr)
				return 1 + minDepth(root->Right);
			else if (root->Right == nullptr)
				return 1 + minDepth(root->Left);
			else
				return 1 + min(minDepth(root->Left), minDepth(root->Right));
		}
	}
	int min(int a, int b)
	{
		return a<b ? a : b;
	}
	void display()const
	{
		for (auto i : _vals)
			std::cout << i << std::endl;
	}
private:
	vector<int> _vals;
};
int main(int argc, char ** argv)
{
	Solution s;
	int a[] = { 6,3,1,7,4,5 };
	TreeNode*root = new TreeNode;
	root = nullptr;//≥ı ºªØ÷∏’Î
	root = InitTree(root, a, 6);
	std::cout<<"minDepth is "<<s.minDepth(root);
	s.display();
	return 0;
}