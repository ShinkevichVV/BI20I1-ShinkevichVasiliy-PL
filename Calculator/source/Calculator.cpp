#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath> 
#include <vector>
#include "Action.h"
#include "Number1.h"
#include "Number2.h"
#include "Scan.h"
#include "Plus.h"
#include "Minus.h"
#include "Multiplication.h"
#include "Division.h"
#include "ShowResult.h"
#include "Trans.h"
#include "Pow.h"

using namespace std;

int main()
{
    setlocale(0, "");
    cout << "Список действий: " << endl;
    cout << "1) + (Сумма двух чисел)" << endl;
	cout << "2) - (Разность двух чисел)" << endl;
	cout << "3) * (Произведение двух чисел)" << endl;
	cout << "4) / (Частное двух чисел)" << endl;
	cout << "5) ^ (Возведение числа в степень)" << endl;
    while (true) {
        vector<char> num1a;
        vector<char> num2a;
        vector<char> res;
        char operand;
        char symbol_1 = '+';
        char symbol_2 = '+';
        cout << "\n";
        Number1(num1a, symbol_1);
        Action(operand);
        cout << "\n";
        Number2(num2a, symbol_2);
        switch (operand) {
        case '+':
            if (symbol_1 == '+' && symbol_2 == '+') {
                fold(num1a, num2a, res);
            }
            else if (symbol_1 == '+' && symbol_2 == '-') {
                subtract(num1a, num2a, res);
            }
            else if (symbol_1 == '-' && symbol_2 == '-') {
                fold(num1a, num2a, res);
                res.push_back('m');
            }
            else if (symbol_1 == '-' && symbol_2 == '+') {
                int flag = scan(num1a, num2a);
                if (flag == 1) {
                    subtract(num1a, num2a, res);
                    res.push_back('m');
                }
                else if (flag == 2) {
                    subtract(num2a, num1a, res);
                }
                else if (flag == 3) {
                    res = { 0 };
                }
            }
            break;
        case '-':
            if (symbol_1 == '+' && symbol_2 == '+') {
                subtract(num1a, num2a, res);
            }
            else if (symbol_1 == '-' && symbol_2 == '-') {
                int flag = scan(num1a, num2a);
                if (flag == 1) {
                    subtract(num1a, num2a, res);
                    res.push_back('m');
                }
                else if (flag == 2) {
                    subtract(num2a, num1a, res);
                }
                else if (flag == 3) {
                    res = { 0 };
                }
            }
            else if (symbol_1 == '+' && symbol_2 == '-') {
                fold(num1a, num2a, res);
            }
            else if (symbol_1 == '-' && symbol_2 == '+') {
                fold(num1a, num2a, res);
                res.push_back('m');
            }
            break;
        case '*':
            if ((symbol_1 == '-' && symbol_2 == '-') || (symbol_1 == '+' && symbol_2 == '+')) {
                multiplication(num1a, num2a, res);
            }
            else {
                multiplication(num1a, num2a, res);
                res.push_back('m');
            }
            break;
        case '/':
            if ((symbol_1 == '-' && symbol_2 == '-') || (symbol_1 == '+' && symbol_2 == '+')) {
                division(num1a, num2a, res);
            }
            else {
                division(num1a, num2a, res);
                res.push_back('m');
            }
            break;
        case '^':
            if ((symbol_1 == '-' && symbol_2 == '-') || (symbol_1 == '+' && symbol_2 == '+')) {
                poww(num1a, num2a, res);
            }
            else {
                poww(num1a, num2a, res);
                res.push_back('m');
            }
        }
        cout << "\nОтвет: ";
        ShowResult(res);
        cout << "\n";
        cout << "\n";
    }
    return 0;
}