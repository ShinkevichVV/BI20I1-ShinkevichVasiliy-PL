#include <iostream>
#include <cmath> 
#include "Multiplication.h"
#include "ScanMultiplication.h"
#include "Plus.h"
#include "Minus.h"

using namespace std;

void multiplication(vector<char>& num1, vector<char>& num2, vector<char>& result) {
    int flag = ScanMultiplication(num1, num2);      
    if (flag == 1) {                                     
        result.push_back('0');
    }
    else if (flag == 2) {
        int counter_null = 0;
        vector<char> pre_result;
        vector<char> subtrahend = { 1 };
        bool flag2 = true;
        do {
            fold(num1, pre_result, result);
            pre_result = result;
            result.clear();
            subtract(num2, subtrahend, result);
            num2 = result;
            result.clear();
            counter_null = 0;
            for (int i = 0; i < num2.size(); i++) {
                if (num2[i] == '0') {
                    counter_null += 1;
                }
            }
            if (counter_null == num2.size()) {
                result = pre_result;
                flag2 = false;
            }
        } while (flag2);
    }
}