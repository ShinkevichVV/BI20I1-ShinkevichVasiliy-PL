#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int x,m, s, d, v;
	int count=x=m=s=d=v=0;
	cout << "Введите число:" << endl;
	cin >> x;
	while (x >= count) {
		cout << count << endl;
		if (count % 2 == 0) {
			s++;
		}
		if (count % 2 == 0) {
			d++;
		}
		if (count % 8 == 0) {
			v++;
		}
		count++;
	}
		cout << "Количество чётных чисел:" << s << endl;
		cout << "Количество чисел, которые делятся на два без остатка:" << d << endl;
		cout << "Количество чисел, которые делятся на восемь без остатка:" << v << endl;
		return 0;
	}
