#include <iostream>
#include "Calculator.h"
using namespace std;

int main()
{
	Calculator calc;//实例化一个对象
	string express;
	getline(cin,express);//比如输入：1+2
	int res = calc.calculate(express);	//运算后的结果
	cout << express << " = " << res << "\n"; 
	
	return 0;
}



