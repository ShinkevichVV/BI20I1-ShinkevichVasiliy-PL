#include <iostream>
#include <cmath> 
#include "Minus.h"
#include "Scan.h"
#include "Trans.h"

using namespace std;

void subtract(vector<char>& num1, vector<char>& num2, vector<char>& result) {
    int number1, number2, iterator;
    int reducer = 0;
    int dif;
    int flag = scan(num1, num2);
    if (flag == 1) {
        for (int i = 0; i < num1.size(); i++) {
            number1 = trans(num1[i]);
            number2 = trans(num2[i]);
            if (number1 - number2 - reducer >= 0) {            
                dif = number1 - number2 - reducer;
                reducer = 0;
                result.push_back(dif);
            }
            else if (number1 - number2 - reducer < 0) {         
                dif = number1 + 10 - number2 - reducer;  
                reducer = 1;                                    
                result.push_back(dif);
            }
        }
    }
    if (flag == 2) {                                            
        for (int i = 0; i < num2.size(); i++) {
            number1 = trans(num1[i]);
            number2 = trans(num2[i]);
            if (number2 - number1 - reducer >= 0) {
                dif = number2 - number1 - reducer;
                reducer = 0;
                result.push_back(dif);
            }
            else if (number2 - number1 - reducer < 0) {
                dif = number2 + 10 - number1 - reducer;
                reducer = 1;
                result.push_back(dif);
            }
        }
        result.push_back('m');
    }
    if (flag == 3) {
        result.push_back('0');
    }
}