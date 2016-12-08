#include"tree.h"
#include<iostream>
#include<vector>
#include<algorithm>
//Given preorder and inorder traversal of a tree, construct the binary tree.

using std::vector;
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		TreeNode *root = nullptr;
		if (!inorder.empty()) {
			auto rootValPtr = std::find(inorder.begin(), inorder.end(), preorder[0]);
			if (rootValPtr != inorder.end())
			{
				root = new TreeNode;
				root->Element=(*rootValPtr);
				preorder.erase(std::remove(preorder.begin(), preorder.end(), preorder[0]), preorder.end());
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
	root = nullptr;//��ʼ��ָ��
	root = InitTree(root, a, 7);
	std::vector<ElementType>preorder;
	std::vector<ElementType>inorder;
	PrintTreeInOrder(root, inorder);
	PrintTreePreOrder(root, preorder);
	display(preorder);
	display(inorder);
//	inorder:1234567  preorder : 6153247;
//	preorder :6//ȡ��preorder�еĵ�һ��Ϊ6
//	inorder:12345 7 //��inorder�е����ݷֳ��������������� preorder:153247//ɾ��ȡ������
//	preorder :1//ȡ����һ����Ϊ1
//	inorder:1 2345//�ֳ��������������� ɾ��ȡ������
//	preorder:5:
//	inorder:234 5
//	preorder:3:
//	inorder 2 4
	TreeNode *tmp=s.buildTree(preorder, inorder);
	//display(tmp);
	std::vector<ElementType>postorder;
	PrintTreePostOrder(tmp, postorder);
	return 0;
}