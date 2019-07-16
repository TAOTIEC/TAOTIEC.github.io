#include <iostream>
#include "Calculator.h"
using namespace std;

//数字
bool Calculator::isDigit(char c)
{
	if(c >= '0' && c <= '9')
		return true;
	else 
		return false;
}

//运算符
bool Calculator::isOperator(char c)
{
	if(c == '+' || c == '-' || c == '*' || c == '/')
	{
		return true;
	}		
	else
	{
		return false;
	}
}

//表达式是否合法
bool Calculator::isValid(string express)
{
	for(int i=0; i<express.size(); i++)
	{
		if( !isDigit(express[i]) || isOperator(express[i]) )
		{
			cout << "express is invalid" << endl;
			return false;
		}
		else
		{
			return true;
		}
	}
}

//运算操作
double Calculator::calculate(string express)
{
	int result = 0;
	int num = 0;
	if( !isValid(express) )
	{
		cout << "express is invalid\n";
	}
	else
	{
		for(int i=0; i<express.size(); i++)
		{
			if( isDigit(express[i]) )
			{
				num = num*10 + express[i]-'0';
			}
			else if( isOperator(express[i]) )
			{
				mOperate = express[i];
				mNum1 = num;
				num = 0;
			}
		}
		mNum2 = num;
		if(mOperate == '+')
		{
			result = mNum1 + mNum2;
		}
		else if(mOperate == '-')
		{
			result = mNum1 - mNum2;
		}
		else if(mOperate == '*')
		{
			result = mNum1 * mNum2;
		}
		else if(mOperate == '/')
		{
			if(mNum2 == 0)
			{
				cout << "除数不能为0\n";
			}
			else
			{
				result = mNum1 / mNum2;
			}
		}
		return result;
	}
}
