#ifndef QUEUE_H
#define QUEUE_H

class Node
{
public:
	Node(int value)
	{
		data = value;
		this->next = nullptr;
	}
	//~Node();
	friend class Queue;

private:
	int data;//
	Node *next;
};


class Queue
{
private:
	Node *mfirst;//头指针
	Node *mlast;//尾指针
	int msize;//实际个数

public:
	Queue()
	{
		mfirst = nullptr;
		mlast = nullptr;
		msize = 0;
	}
	//~Queue();
	void EnQueue(int value);//入队
	int DeQueue();//出队
	bool isEmpty();//是否为空
	int size();//元素实际个数
	void Print_Que();//打印队列元素
};



#endif