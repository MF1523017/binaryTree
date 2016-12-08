#include"tree.h"
#include<iostream>
#include<vector>
//Invert a binary tree.
//
//      4
//     /  \
//    2    7
//  / \   / \
// 1   3 6   9
//to
//     4
//    / \
//   7   2
//  / \  / \
// 9   6 3   1

using std::vector;
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root != nullptr)
		{
			TreeNode* tmpleft = invertTree(root->Left);//取出左叶子
			TreeNode* tmpright = invertTree(root->Right);//取出右叶子
			swap(root, tmpleft, tmpright);//交换位置
		}
		return root;
	}
	void swap(TreeNode *root, TreeNode *left, TreeNode *right)
	{
		TreeNode *tmp = left;
		root->Left = right;
		root->Right = tmp;
	}

};
int main(int argc, char ** argv)
{
	Solution s;
	int a[] = { 4,2,7,1,3,6,9 };
	TreeNode*root = new TreeNode;
	root = nullptr;//初始化指针
	root = InitTree(root, a, 7);
	PrintTreeInOrder(root);
	s.invertTree(root);
	std::cout << std::endl;
	PrintTreeInOrder(root);
	//s.display();
	return 0;
}