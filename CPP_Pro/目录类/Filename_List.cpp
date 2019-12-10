#include "Filename_List.h"
#include <iostream>
using namespace std;

void FNlist::Insert(string name)//插入文件名节点
{
	Node *pNode = new Node(name);
	if( this->isEmpty() )
	{
		mfirst = pNode;
		mlast = pNode;
	}
	else
	{
		//尾插法
		mlast->_next = pNode;
		mlast = pNode;
	}	
	msize++;
}

bool FNlist::isEmpty()
{
	return msize == 0;
}

void FNlist::PrintList()//打印
{
	Node *temp = mfirst;
	while( temp != nullptr)
	{
		cout << temp->_name << " ";
		temp = temp->_next;
	}
	cout << endl;
}



