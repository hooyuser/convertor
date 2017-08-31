#include "stack.h"
#include <iostream>
#include <string>

void convert(Stack<char>& S, __int64 n, int base)  //十进制数n到base进制的转换（迭代版）
{
	static char digit[] //0 < n, 1 < base <= 16，新进制下的数位符号，可视base取值范围适当扩充
		= { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	while (n > 0)
	{ //由低到高，逐一计算出新进制下的各数位
		int remainder = (int)(n % base);
		S.push(digit[remainder]); //余数（当前位）入栈
		n /= base; //n更新为其对base的除商
	}
} //新进制下由高到低的各数位，自顶而下保存于栈S中


int main()
{
	using namespace std;

	Stack<char> S;
	int base = 2;
	int n = 0;

	cout << "Input the decimal number to be converted:";
	cin >> n;
	cout << "Input the base:";
	cin >> base;
	convert(S, n, base);
	cout << "The convertion result:";
	while (!S.empty())
		cout << S.pop();

	cin.get();
	cin.get();
	return 0;
}