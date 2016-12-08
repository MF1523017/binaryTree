#ifndef TREE_H
#define TREE_H
#include<iostream>
#include<vector>

struct TreeNode;
typedef int ElementType ;
typedef struct TreeNode* SearchTree ;
typedef SearchTree Position;
SearchTree InitTree(SearchTree T, ElementType *buff,int buff_size);
SearchTree MakeEmpty(SearchTree T);
SearchTree Find(SearchTree T,ElementType e);
SearchTree FindMin(SearchTree T);
SearchTree FindMax(SearchTree T);
SearchTree Insert(SearchTree T,ElementType e);
SearchTree Delete(SearchTree T,ElementType e);
void PrintTreeInOrder(SearchTree T, std::vector<ElementType> &rhs);
void PrintTreePreOrder(SearchTree T, std::vector<ElementType> &rhs);
void PrintTreePostOrder(SearchTree T, std::vector<ElementType> &rhs);

void display(std::vector<ElementType> &rhs);
struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
	//TreeNode(ElementType e) :Element(e), Left(nullptr), Right(nullptr) {};
};

#endif // TREE_H
