#include <iostream>
#include <cmath> 
#include "Pow.h"
#include "ScanPow.h"
#include "Plus.h"
#include "Multiplication.h"
#include "Trans.h"
#include "Scan.h"

using namespace std;

void poww(vector<char>& num1, vector<char>& num2, vector<char>& result) {
    int flag = ScanPow(num1, num2);
    int length1 = num1.size();
    int length2 = num2.size();
    if (flag == 1) {
        result.push_back('0');
    }
    else if (flag == 2) {
        result.push_back('1');
    }
    else if (flag == 3) {
        for (int i = 0; i < num2.size(); i++) {
            multiplication(num1, num1, result);
        }
    }
}
