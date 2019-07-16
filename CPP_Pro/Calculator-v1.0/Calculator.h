#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <iostream>
using namespace std;

class Calculator
{
private: //属性
	int mNum1;//操作数1
	int mNum2;//操作数2
	char mOperate;//运算符
	bool isDigit(char c);
	bool isOperator(char c);
		
public://功能
	bool isValid(string express);
	double calculate(string express);
};


#endif