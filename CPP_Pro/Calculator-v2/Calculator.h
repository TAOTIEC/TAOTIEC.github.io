#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "Queue.h"
#include <iostream>
using namespace std;

class Calculator
{
private:
	int num1;
	int num2;
	char opr;
	double result;
	bool isDigit(int c);//是否数字
	bool isOperate(int c);//是否运算符
	bool isSpace(int c);//是否有空格
	Queue Infix_Que;//中缀队列
	Queue Postfix_Que;//后缀队列
	void AnalysisExpress(string express);//解析表达式，并将元素放到中缀队列
	void ConvertExpress();//中缀转后缀
	int priority(int c);//比较符号 优先级
	void runexpress();//真正的运算
	void calculateExpress();//

public:
	Calculator()
	{
		num1 = 0;
		num2 = 0;
	}
	bool isValid(string express);//表达式是否合法
	double calculator(string express);//运算操作
	int test();
};



#endif