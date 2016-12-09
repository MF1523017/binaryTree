#ifndef TREE_H
#define TREE_H
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
void PrintTreeInOrder(SearchTree T);
void PrintTreePreOrder(SearchTree T);
void PrintTreePostOrder(SearchTree T);
struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
	//TreeNode(ElementType e) :Element(e), Left(nullptr), Right(nullptr) {};
};

#endif // TREE_H
