#include <iostream>
#include <cmath> 
#include "Division.h"
#include "ScanDivision.h"
#include "Plus.h"
#include "Minus.h"

using namespace std;

void division(vector<char>& num1, vector<char>& num2, vector<char>& result) {
    int flag = ScanDivision(num1, num2);
    if (flag == 1) {                  
        result.push_back(0);
        return;
    }
    else if (flag == 2) {             
        result.push_back('e');        
        return;
    }
    else if (flag == 3) {
        vector<char> summand = { 1 };
        vector<char> counter_iteration = { 0 };
        bool flag2 = true;
        do {
            fold(counter_iteration, summand, result);     
            counter_iteration = result;                      
            result.clear();
            subtract(num1, num2, result);
            num1 = result;
            result.clear();
            flag = ScanDivision(num1, num2);       
            if (flag == 1) {
                result = counter_iteration;
                flag2 = false;
            }
            else if (flag == 4) {
                result = counter_iteration;
                flag2 = false;
            }
            else if (flag == 5) {
                fold(counter_iteration, summand, result);
                flag2 = false;
            }
        } while (flag2);
    }
    else if (flag == 4) {
        result.push_back(0);
        return;
    }
    else if (flag == 5) {
        result.push_back(1);
        return;
    }
}