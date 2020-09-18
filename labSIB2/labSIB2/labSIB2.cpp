#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int x;
	srand(time(NULL));
	int a = rand() % 100;
	cout << a;
	do {
		cout << "Введите число:" << endl;
		cin >> x;
		if (a < x) {
			cout << "Загаданное число меньше" << endl;
		}
		else if (a > x) {
			cout << "Загаданное число больше" << endl;
		}
		else {
			cout << "Число угадано:" << a << endl;
			system("pause");
			return 0;
		}
	} while (a != x);
}