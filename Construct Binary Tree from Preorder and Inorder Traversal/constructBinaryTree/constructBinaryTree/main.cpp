#include"tree.h"
#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		TreeNode *root = nullptr;
		if (!inorder.empty()) {
			auto rootValPtr = find(inorder.begin(), inorder.end(), preorder[0]);
			if (rootValPtr != inorder.end())
			{
				root = new TreeNode;
				root->Element=(*rootValPtr);
				preorder.erase(remove(preorder.begin(), preorder.end(), preorder[0]), preorder.end());
				if (rootValPtr != inorder.begin())
				{
					vector<int> tmp(inorder.begin(), rootValPtr);
					root->Left = buildTree(preorder, tmp);
				}
				if (rootValPtr != inorder.end() - 1)
				{
					vector<int> tmp(rootValPtr + 1, inorder.end());
					root->Right = buildTree(preorder, tmp);
				}
			}
		}
		return root;
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
	int a[] = { 6,1,5,3,2,4,7 };
	TreeNode*root = new TreeNode;
	root = nullptr;//≥ı ºªØ÷∏’Î
	root = InitTree(root, a, 7);
	std::vector<ElementType>preorder;
	std::vector<ElementType>inorder;
	PrintTreeInOrder(root, inorder);
	PrintTreePreOrder(root, preorder);
	display(preorder);
	display(inorder);

	TreeNode *tmp=s.buildTree(preorder, inorder);
	//display(tmp);
	PrintTreeInOrder(tmp, preorder);
	return 0;
}