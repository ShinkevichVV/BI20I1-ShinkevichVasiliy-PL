#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int x, s, b, z;
	s = 1000;
	cout << "Баланс равен = " << s << endl;
	do {
		srand(time(NULL));
		int a = rand() % 22;
		cout << a;
		do {
			cout << "Введите сумму ставки: " << endl;
			cin >> b;
			if ((b == 0) || (b > s) || (b < 0)) {
				cout << "Введите другую сумму " << endl;
			}
			else {
				cout << "Ставка принята: " << b << endl;
			}
		} while ((b > s) || (b == 0));
		do {
			cout << "Введите число от 0 до 21: " << endl;
			cin >> x;
		} while ((x > 21) || (x < 0));
		if (x == a) {
			cout << "Вы угадали число: " << a << endl;
			s += b * 4;
			cout << "Баланс равен = " << s << endl;
		}
		else if ((x == a - 2) || (x == a + 2)) {
			cout << "Число в пределе +-2: " << a << endl;
			s += b * 2;
			cout << "Баланс равен = " << s << endl;
		}
		else {
			cout << "Вы проиграли " << a << endl;
			s -= b;
			cout << "Баланс равен = " << s << endl;	
		}
	} while ((s == 0) || (s < 3000));
}