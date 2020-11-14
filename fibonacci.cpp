#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
unsigned long int x(int n)
{
    setlocale(LC_ALL, "Russian");
    if (n == 1 || n == 2) { return 1; };
    if (n == 0) { return 0; };

    return x(n - 2) + x(n - 1);
}
int main()
{
    for (int i=0; i < 51; i++) 
    {
        cout << x(i); cout << " - №"; cout << i << endl;
    }
    return 0;
}