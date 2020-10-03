#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
	int i, j, x;
	int f[5];
	int a[5] = { 1, 2, 3, 4, 5 };
	int* pa;
	pa = &a[0];
	setlocale(LC_ALL, "Russian");
	for (i = 0; i < 5; i++) {
		cout << a[i] << endl;
	}
	for (i = 0; i < 5; i++) {
		*pa = *(pa + 4);
		*(pa + 1) = *(pa + 3);
		*(pa + 3) = *(pa + 1);
		*(pa + 4) = *pa;
	}
	cout << "Измененная" << endl;
	for (i = 0; i < 5; i++) {
		cout << a[i] << endl;
	}
}