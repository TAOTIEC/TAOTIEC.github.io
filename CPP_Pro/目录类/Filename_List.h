


#ifndef FILENAME_LIST_H
#define FILENAME_LIST_H
#include <string.h>
#include <iostream>
using namespace std;


class Node
{
public:
	Node(string name)
	{
		_name = name;
		_next = nullptr;
	}
	//~Node();
	friend class FNlist;

private:
	string _name;//文件名
	Node *_next;
	
};


class FNlist
{
private:
	Node *mfirst;//头指针，指向链表第一个节点
	Node *mlast;//尾指针，指向链表最后一个节点
	int msize;//链表元素的 实际个数

public:
	FNlist()
	{
		mfirst = nullptr;
		mlast = nullptr;
		msize = 0;
	}
	//~FNlist();
	void Insert(string name);//插入
	bool isEmpty();//判断是否 为空
	void PrintList();//打印

};


#endif


