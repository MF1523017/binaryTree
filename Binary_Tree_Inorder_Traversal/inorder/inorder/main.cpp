#include"tree.h"
#include<iostream>
#include<vector>
using std::vector;
class Solution {
public:
	Solution() = default;
	vector<int> inorderTraversal(TreeNode* root) {
		inorder(root);
		return _vals;
	}
	void inorder(TreeNode * root)
	{
		if (root != nullptr)
		{
			inorder(root->Left);
			_vals.push_back(root->Element);
			inorder(root->Right);
		}
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
	int a[] = { 0,1,2,3,4,5 };
	TreeNode*root = new TreeNode;
	root = nullptr;//≥ı ºªØ÷∏’Î
	root = InitTree(root, a, 6);
	s.inorderTraversal(root);
	s.display();
	return 0;
}