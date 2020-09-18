#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
		int x,s,d,v;
		cout << "Введите число:" << endl;
		cin >> x;
		s = (x / 2) + 1;
		d = x / 2;
		v = x / 8;
		cout << "Количество чётных чисел:" << s << endl;
		cout << "Количество чисел, которые делятся на два без остатка:" << d << endl;
		cout << "Количество чисел, которые делятся на восемь без остатка:" << v << endl;
		return 0;
}