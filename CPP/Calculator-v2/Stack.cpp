#include "Stack.h"
#include <iostream>
using namespace std;

void Stack::PushStack(int value)//入栈
{
	//只要栈不是满的，就可以入栈
	if( this->isFull() )
	{
		throw "Stack is full!\n";
	}
	else
	{
		mdata[++top] = value;
	}
}

int Stack::PopStack()//出栈
{
	//只要不是空的，就可以出栈
	if( this->isEmpty() )
	{
		throw "Stack is empty!\n";
	}
	else
	{
		return mdata[top--];
	}
}


bool Stack::isFull()//是否满了
{
	return top == mcapacity-1;
}

bool Stack::isEmpty()//是否为空
{
	return top == -1;
}

int Stack::size()//栈中的实际个数
{
	return top + 1;
}

int Stack::GetTop()//获取栈顶元素
{
	return mdata[top];
}

