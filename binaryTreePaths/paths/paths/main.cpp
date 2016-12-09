#include"tree.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
//Given a binary tree, return all root - to - leaf paths.
//
//For example, given the following binary tree :
//
//    1
//   / \
//  2   3
//   \
//    5
//All root - to - leaf paths are :
//
// ["1->2->5", "1->3"]

using std::vector;
using std::string;
using std::to_string;
class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {

		if (root != nullptr)
		{
			paths(root, string(""));
		}
		//_paths.erase(std::unique(_paths.begin(), _paths.end()), _paths.end());
		return _paths;
	}
	void paths(TreeNode* root,string t)
	{
		if (root == nullptr)
		{
			_paths.push_back(t);
			return;
		}
		t = t + to_string(root->Element);
		if (root->Left == nullptr&&root->Right == nullptr) {
			//string tmp = t + to_string(root->Element);
			paths(root->Left, t);
		}
		else {
			//string tmp = t + to_string(root->Element);
			if (root->Left!=nullptr)
				paths(root->Left, t + "->");
			if(root->Right!=nullptr)
				paths(root->Right, t + "->");
		}
		/*if (root->Right == nullptr)
		{
			string tmp = t + to_string(root->Element);
			paths(root->Right, tmp);
		}
		else
		{
			string tmp = t + to_string(root->Element);
			paths(root->Right, tmp + "->");
		}*/
	}
private:
	vector<string>_paths;
};
int main(int argc, char ** argv)
{
	Solution s;
	int a[] = { 4,2,7,1,3,6,9 };
	TreeNode*root = new TreeNode;
	root = nullptr;//≥ı ºªØ÷∏’Î
	root = InitTree(root, a, 7);
	PrintTreeInOrder(root);
	s.binaryTreePaths(root);
	std::cout << std::endl;
	PrintTreeInOrder(root);
	//s.display();
	return 0;
}