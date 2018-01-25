#include "stack.h"
#include <iostream>


void convert(Stack<char>& S, __int64 n, int base) //ʮ������n��base���Ƶ�ת�����������ջS��
{	
	static char digit[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };//0 < n, 1 < base <= 16���½����µ���λ���ţ�����baseȡֵ��Χ�ʵ�����
	while (n > 0)
	{ //�ɵ͵��ߣ���һ������½����µĸ���λ
		int remainder = (int)(n % base);
		S.push(digit[remainder]); //��������ǰλ����ջ
		n /= base; //n����Ϊn����base����
	}
} //�½������ɸߵ��͵ĸ���λ���Զ����±�����ջS��

int main()
{
	using namespace std;

	Stack<char> S;
	__int64 n = 0;
	int base = 2;

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