#include <iostream>
#include "Calculator.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;


bool Calculator::isDigit(int c)//数字
{
	return c >= '0' && c <= '9';
}


bool Calculator::isOperate(int c)//运算符
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

bool Calculator::isSpace(int c)//是否有空格
{
	return c == ' ';
}

bool Calculator::isValid(string express)//表达式是否合法
{
	for(int i = 0; i < express.size(); i++)
	{
		if( !isDigit(express[i]) || isOperate(express[i]) || isSpace(express[i]) )//第一个字符不是数字或者是符，不合法
		{
			cout << "express is invalid\n";
			return false;
		}
		else if(!(isDigit(express[i])) && (i == express.size() -1) )//最后一个字符不是数字，不合法
		{
			cout << "express is invalid\n";
			return false;
		}
		else
		{
			return true;
		}
	}
}

double Calculator::calculator(string express)
{
	//判断表达式是否合法
	bool ok = isValid(express);
	if( !ok )
	{
		throw "express is invalid!\n";
	}
	//解析表达式，将元素顺序放入中缀队列中
	AnalysisExpress(express);
	//cout << endl;
	//Infix_Que.Print_Que();//打印中缀队列中 已有元素

	//中缀转后缀
	/*中缀：1+2
	后缀：12+*/
	ConvertExpress();
	//cout << endl;
	//Postfix_Que.Print_Que();//打印后缀队列中 已有元素

	//真正的计算
	runexpress();

	return result;
}

void Calculator::AnalysisExpress(string express)//解析表达式，并将元素放到中缀队列
{
	string str;//存数字字符

	for(int i=0; i < express.size(); i++)
	{
		char c = express[i];
		if( isDigit(c) )//将数字字符存入字符串中，再转成整型数字后放入中缀队列
		{
			str += c;
		}
		if( isOperate(c) )
		{
			opr = c;
			num1 = atoi(str.c_str());
			Infix_Que.EnQueue(num1);
			Infix_Que.EnQueue(opr);
			str.clear();
		}
	}
	num2 = atoi(str.c_str());
	Infix_Que.EnQueue(num2);
}

void Calculator::ConvertExpress()//中缀转后缀
{
	Stack stack(10);//暂存 运算符
	while( !Infix_Que.isEmpty() )
	{
		int value = Infix_Que.DeQueue();//临时value接收 中缀队列出来 的元素
		//cout << value << "出队 ";
		if( !isOperate(value) )//如果不是符，就是数
		{
			Postfix_Que.EnQueue(value);
		}
		else			//是符，需要比较 符的 优先级
		{
			while(1)
			{
				if( stack.isEmpty() )//栈空，符直接进栈
				{
					stack.PushStack(value);
					break;
				}
				else
				{
					if( priority(value) > priority(stack.GetTop()) )//当前符 优先 栈顶符
					{
						stack.PushStack(value);//符 进栈
						break;
					}
					else									//弹出栈顶元素，入后缀队
					{
						Postfix_Que.EnQueue( stack.PopStack() );
					}
				}
			}
		}
	}
	while( !stack.isEmpty() )
	{
		Postfix_Que.EnQueue( stack.PopStack() );
	}
}

int Calculator::priority(int c)//比较符号 优先级
{
	if( c == '+' || c == '-' )
	{
		return 1;
	}
	else if( c == '*' || c == '/' )
	{
		return 2;
	}
}

void Calculator::runexpress()//真正的运算
{
	Stack inner(10);//暂存 数字的 栈
	while( !( Postfix_Que.isEmpty() ) )//后缀队不为空
	{
		char c = Postfix_Que.DeQueue();
		if( !isOperate(c) )
		{
			inner.PushStack(c);//数字 进栈
		}
		else
		{
			num1 = inner.PopStack();
			num2 = inner.PopStack();
			opr = c;
			calculateExpress();
			inner.PushStack(result);
		}
	}
}

void Calculator::calculateExpress()
{
	if (opr == '+')
	{
		result = num1 + num2;
	}
	else if (opr == '-')
	{
		result = num1 - num2;
	}
	else if (opr == '*')
	{
		result = num1 * num2;
	}
	else
	{
		if (num2 == 0)
		{
			throw "除数不能为零";
		}
		result = num2 *1.0 / num1;
	}
}

int Calculator::test()
{
	int res = 0;//运算结果
	string express;//表达式
	while(1)
	{
		getline(cin,express);
		if(express == "exit")
		{
			return 0;
		}
		else
		{
			if( isValid(express) )
			{
				res = calculator(express);
				cout << express << " = " << res << endl;
				cout << "------运算结束(输入:exit 离开)-------\n";
			}
			else
			{
				cout << "express is invalid!\n";
			}
		}
	}
}

/*
中缀表达式： 1+2
后缀表达式： 12+

1 + 2 * 3 => 123*+
中缀转后缀：		用栈处理运算符
计算后缀表达式：	用栈处理操作数
*/