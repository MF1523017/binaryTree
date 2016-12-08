#include"tree.h"
#include<iostream>
#include<vector>
//Given a binary tree, determine if it is height - balanced.

//For this problem, a height - balanced binary tree is defined 
//as a binary tree in which the depth of the two subtrees of 
//every node never differ by more than 1.

using std::vector;
class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (root == nullptr)
			return true;
		int leftHeight = height(root->Left);
		int rightHeight = height(root->Right);
		return abs(leftHeight - rightHeight) <= 1 && isBalanced(root->Left) && isBalanced(root->Right);
	}
	int height(TreeNode* root)
	{
		if (root == nullptr)
			return -1;
		else
			return 1 + max(height(root->Left), height(root->Right));

	}
	int max(int a, int b)
	{
		return a>b ? a : b;
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
	int a[] = { 1,2 };
	TreeNode*root = new TreeNode;
	root = nullptr;//≥ı ºªØ÷∏’Î
	root = InitTree(root, a, 2);
	std::cout<<"isBalanced is "<<s.isBalanced(root);
	s.display();
	return 0;
}