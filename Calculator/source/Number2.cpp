#include <iostream>
#include <cmath> 
#include <vector>
#include <string>
#include "Number2.h"

using namespace std;

vector<char> Number2(vector<char>& number, char& symbol) {
    bool condition = true;
    while (condition) {
        std::cout << "Второе число: ";
        string Number;
        getline(cin, Number);
        for (int i = Number.length() - 1; i >= 0; i--) {
            //if (i == 0 && Number[i] = '-')
            if (Number[i] == '0' || Number[i] == '1' || Number[i] == '2' || Number[i] == '3' ||
                Number[i] == '4' || Number[i] == '5' || Number[i] == '6' || Number[i] == '7' ||
                Number[i] == '8' || Number[i] == '9') {
                number.push_back(Number[i]);
                if (i == 0) {
                    condition = false;
                }
            }
            else {
                if (i == 0 && Number[i] == '-') {
                    symbol = '-';
                    condition = false;
                }
                else {
                    cout << "Вы ввели неправильное число" << endl;
                    number.clear();
                    break;
                }
            }
        }
    }
    cout << "\n";
    return number;
}