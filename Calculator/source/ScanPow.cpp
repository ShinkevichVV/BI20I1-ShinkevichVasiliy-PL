#include <iostream>
#include <cmath> 
#include "ScanPow.h"
#include "Trans.h"

int ScanPow(vector<char>& num1, vector<char>& num2) {
    int number1, number2;
    int flag = 0;
    int counter_null_num1 = 0;
    int counter_null_num2 = 0;
    for (int i = 0; i < num1.size(); i++) {
        number1 = trans(num1[i]);
        if (num1[i] == '0') {
            counter_null_num1 += 1;
        }
    }
    for (int i = 0; i < num2.size(); i++) {
        number2 = trans(num2[i]);
        if (num2[i] == '0') {
            counter_null_num2 += 1;
        }
    }
    if (counter_null_num1 == num1.size()) {
        flag = 1;
    }
    else if (counter_null_num2 == num2.size()) {
        flag = 2;
    }
    else if (num1.size() > num2.size()) {
        flag = 3;
    }
    else if (num1.size() < num2.size()) {
        flag = 3;
    }
    if (num1.size() == num2.size()) {
        flag = 3;
    }
    return flag;
}