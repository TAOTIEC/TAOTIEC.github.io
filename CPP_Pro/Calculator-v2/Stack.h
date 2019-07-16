#ifndef STACK_H
#define STACK_H

class Stack
{
private:
	int top;//栈顶元素下标
	int *mdata;//数组，存栈元素
	int mcapacity;//栈容量

public:
	Stack(int capacity)
	{
		top = -1;
		mcapacity = capacity;
		mdata = new int[mcapacity];
	}
	~Stack()
	{
		delete []mdata;
	}
	void PushStack(int value);//入栈
	int PopStack();//出栈
	bool isFull();//是否满了
	bool isEmpty();//是否为空
	int size();//栈中的实际个数
	int GetTop();//获取栈顶元素
};



#endif