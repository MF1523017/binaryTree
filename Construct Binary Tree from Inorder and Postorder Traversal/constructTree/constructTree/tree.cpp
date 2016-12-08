#include"tree.h"
#include<iostream>
//二叉查找树，左子树永远小于右子树，
SearchTree InitTree(SearchTree T, ElementType *buff,int buff_size)
{
	//T = nullptr;
	T = MakeEmpty(T);
	for (int i=0; i < buff_size; ++i)
		T = Insert(T, buff[i]);
	return T;
}
SearchTree MakeEmpty(SearchTree T)
{
    if (T!=nullptr)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        delete T;
    }
	return T;
}
SearchTree Find(SearchTree T,ElementType e)
{
    if (T==nullptr)
        return T;
    if (e<T->Element)
        return Find(T->Left,e);
    else if(e>T->Element)
        return Find(T->Right,e);
    else
        return T;
}
SearchTree FindMin(SearchTree T)
{
    if (T==nullptr)
        return T;
    else if (T->Left==nullptr)
        return T;
    else
        return FindMin(T->Left);
}
SearchTree FindMax(SearchTree T)
{
    if (T==nullptr)
        return T;
    else if (T->Right==nullptr)
        return T;
    else
        return FindMax(T->Right);
}
SearchTree Insert(SearchTree T,ElementType e)
{
	
    if (T==nullptr){
        T=new TreeNode;
        T->Element=e;
        T->Left=T->Right=nullptr;
        }
    if (e<T->Element)
        T->Left=Insert(T->Left,e);
    else if(e>T->Element)
        T->Right=Insert(T->Right,e);
    return T;
}
SearchTree Delete(SearchTree T,ElementType e)
{
	Position tmp;
	if (T==nullptr)
		return T;
	else if(e<T->Element)
		T->Left=Delete(T->Left,e);
	else if (e>T->Element)
		T->Right=Delete(T->Right,e);
	else if(T->Left&&T->Right)
	{
		tmp=FindMin(T->Right);
		T->Element=tmp->Element;
		T->Right=Delete(T->Right,tmp->Element);
	}
	else
	{
		tmp=T;
		if (T->Left==nullptr)
			T=T->Right;
		else if(T->Right==nullptr)
			T=T->Left;
		delete tmp;
	}
	return T;

}
void PrintTreePostOrder(SearchTree T, std::vector<ElementType> &rhs)
{
	if(T!=nullptr)
	{
		PrintTreePostOrder(T->Left,rhs);
		PrintTreePostOrder(T->Right,rhs);
		std::cout<<T->Element<<" ";
		rhs.push_back(T->Element);
	}
}
void PrintTreePreOrder(SearchTree T, std::vector<ElementType> &rhs)
{
	if(T!=nullptr)
	{
		std::cout<<T->Element<<" ";
		rhs.push_back(T->Element);
		PrintTreePreOrder(T->Left,rhs);
		PrintTreePreOrder(T->Right,rhs);
		
	}
}
void PrintTreeInOrder(SearchTree T, std::vector<ElementType> &rhs)
{
	if(T!=nullptr)
	{
		PrintTreeInOrder(T->Left,rhs);
		std::cout<<T->Element<<" ";
		rhs.push_back(T->Element);
		PrintTreeInOrder(T->Right,rhs);
	}
}
void display(std::vector<ElementType> &rhs)
{
	for (auto i : rhs)
		std::cout << i << " ";
	std::cout << std::endl;
}

