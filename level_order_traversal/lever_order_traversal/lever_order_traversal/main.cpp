#include"tree.h"
#include<iostream>
#include<vector>
#include<queue>
using std::vector;
using std::queue;
class Solution {
public:
	//����һ
	vector<vector<int>> levelOrder(TreeNode* root) {
		//vector<vector<int> >  result;
		if (!root) return _vals;
		queue<TreeNode*> q;//q���������е�Ԫ��˳��Ϊ [6 NULL 2 9 NULL 1 5 7]
		q.push(root);
		q.push(NULL);
		vector<int> cur_vec;
		//cur_vec.clear();
		while (!q.empty()) {
			TreeNode* t = q.front();
			q.pop();
			if (t == NULL) {
				_vals.push_back(cur_vec);
				cur_vec.resize(0);
				if (q.size() > 0) {
					q.push(NULL);//ͨ��NULL��Ϊ���������ÿһ��
				}
			}
			else {
				cur_vec.push_back(t->Element);
				if (t->Left) 
					q.push(t->Left);
				if (t->Right) 
					q.push(t->Right);
			}
		}
		return _vals;
	}
	
	//������
	void buildVector(TreeNode *root, int depth)
	{
		if (root == NULL) return;
		if (_vals.size() == depth)
			_vals.push_back(vector<int>());// vector<int>() //construct empty vector

		_vals[depth].push_back(root->Element);
		buildVector(root->Left, depth + 1);
		buildVector(root->Right, depth + 1);
	}

	vector<vector<int> > levelOrder2(TreeNode *root) {
		buildVector(root, 0);
		return _vals;
	}
	void display()const
	{
		for (auto i : _vals) {
			for (auto j : i) {
				std::cout << j << " ";
			}
			std::cout << std::endl;
		}
	}
private:
	vector<vector<int> >  _vals;
};
int main(int argc, char ** argv)
{
	Solution s;
	int a[] = { 6,9,7,2,1,5 };
	
	/*��������������ʽ����
       6
 	 2   9
	1 5 7
	*/
	TreeNode*root = new TreeNode;
	root = nullptr;//��ʼ��ָ��
	root = InitTree(root, a, 6);
	//PrintTreeInOrder(root);
	//s.levelOrder(root);
	s.levelOrder2(root);
	s.display();
	return 0;
}