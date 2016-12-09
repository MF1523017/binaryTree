#include"tree.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
//Given a binary tree, find the lowest common ancestor(LCA) of two given nodes in the tree.
//
//According to the definition of LCA on Wikipedia : “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants(where we allow a node to be a descendant of itself).”
//
//_______3______
//	   /    \
//___5__    ___1__
//  / \       / \
// 6   _2    0    8
//    / \
//   7   4
//For example, the lowest common ancestor(LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.



using std::vector;
using std::string;
using std::to_string;
using std::stack;
class Solution {
public:
	TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr)
			return root;
		if (root == p || root == q)
			return root;
		TreeNode *tmpleft = lowestCommonAncestor2(root->Left, p, q);
		TreeNode *tmpright = lowestCommonAncestor2(root->Right, p, q);
		if (tmpleft&&tmpright)
			return root;
		return (tmpleft != nullptr) ? tmpleft : tmpright;
	
	}
	//暴力解法，将从根节点到每个节点的路径保存下来，两个路径比较相同的节点，即是共同的祖先！
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		_pvec = getPath(root, p);
		_qvec = getPath(root, q);
		TreeNode *tmp = nullptr;
		for (vector<TreeNode*>::reverse_iterator b = _pvec.rbegin(); b != _pvec.rend(); ++b)
		{
			vector<TreeNode*>::iterator result = std::find(_qvec.begin(), _qvec.end(), *b);
			if (result != _qvec.end()) {
				tmp= *result;
				break;
			}
		}
		return tmp;
		//return root;
	}
	
	vector<TreeNode *> getPath(TreeNode *root, TreeNode *des)
	{
		//stack<TreeNode *> ts;
		vector<TreeNode *> ts;
		if (root == nullptr)
			return ts;
		TreeNode *tmp = root;
		ts.push_back(root);
		while (1)
		{
			if (tmp== des)
			{
				break;
			}
			else if (tmp->Left == des|| tmp->Right == des)
			{
				ts.push_back(des);
				break;
			}
			else if (tmp->Left == nullptr&&tmp->Right == nullptr)
			{
				ts.pop_back();
				tmp = ts.back();
				tmp = tmp->Right;
				if (tmp != des)
				{
					ts.pop_back();
					tmp = ts.back()->Right;
					ts.push_back(tmp);
				}
			}
			else
			{
				tmp = tmp->Left;
				ts.push_back(tmp);
			}
		}
		return ts;
	}

private:
	vector<TreeNode*> _pvec;
	vector<TreeNode*> _qvec;
};
int main(int argc, char ** argv)
{
	Solution s;
	int a[] = {7,4,1,5,3,2};
	TreeNode*root = new TreeNode;
	root = nullptr;//初始化指针
	root = InitTree(root, a, 6);
	//PrintTreeInOrder(root);
	std::cout<<s.lowestCommonAncestor2(root,root->Left,root->Left->Right)->Element;
	std::cout << std::endl;
	//PrintTreeInOrder(root);
	//s.display();
	return 0;
}