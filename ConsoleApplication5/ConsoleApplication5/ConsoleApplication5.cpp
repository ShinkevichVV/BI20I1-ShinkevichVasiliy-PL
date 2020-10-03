#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
	int j, i, m[100];
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	for (i = 0; i < 100; i++) {
		m[i] = rand() % 500;
		cout << m[i] << endl;
	}
	for (i = 0; i < 100; i++) {
		for (j = 0; j < 100 - (i+1); j++) {
			if (m[j] > m[j + 1]) {
				int t = m[j];
				m[j] = m[j + 1];
				m[j + 1] = t;
			}
		}
	} cout << "Сортировка:" << endl;
	for (i = 0; i < 100; i++) {
		cout << i << " Элемент = " << m[i] << " " << endl;
	}
	system("pause");
	return 0;

}
	

	