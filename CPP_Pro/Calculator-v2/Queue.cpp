#include "Queue.h"
#include <iostream>
using namespace std;

void Queue::EnQueue(int value)//入队
{
	Node *pNode = new Node(value);
	//如果满了就不能进来，其他情况都能进来
	if( this->isEmpty() )
	{
		mfirst = pNode;
		mlast = pNode;
	}
	else	//尾插法
	{
		mlast->next = pNode;
		mlast = pNode;
	}
	++msize;
	//cout << pNode->data << "入队 ";
}


int Queue::DeQueue()//出队
{
	if( isEmpty() )
	{
		throw "Queue is empty!\n";
	}

	int value = mfirst->data;
	if( msize == 1)
	{
		delete mfirst;
		mfirst = nullptr;
		mlast = nullptr;
	}
	else
	{
		Node *temp = mfirst->next;
		delete mfirst;
		mfirst = temp;
	}
	msize--;
	return value;
}


bool Queue::isEmpty()//是否为空
{
	return msize == 0;
}


int Queue::size()//元素实际个数
{
	return msize;
}


void Queue::Print_Que()//打印队列元素
{
	Node *temp = mfirst;
	while(temp != nullptr)
	{
		cout << temp->data << " ";//打印队中 已有元素
		temp = temp->next;
	}
	cout << endl;
}


