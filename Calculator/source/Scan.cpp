#include <iostream>
#include <cmath> 
#include "Scan.h"
#include "Trans.h"

int scan(vector<char>& num1, vector<char>& num2) {
    int number1, number2;
    int length1 = num1.size();
    int length2 = num2.size();
    int flag = 0;
    int counter_equality;
    if (length1 > length2) {                            
        for (int i = 0; i < length1 - length2; i++) {   
            num2.push_back(0);
            flag = 1;
        }
    }
    else if (length1 < length2) {                     
        for (int i = 0; i < length2 - length1; i++) {                  
            num1.push_back(0);
            flag = 2;
        }
    }
    else {
        for (int i = num1.size() - 1; i >= 0; i--) {         
            number1 = trans(num1[i]);
            number2 = trans(num2[i]);
            if (number1 > number2) {                         
                flag = 1;                                    
                break;
            }
            else if (number1 < number2) {                    
                flag = 2;
                break;
            }
            else if (number1 == number2) {
                if (i == 0) {
                    flag = 3;
                }
            }
        }
    }
    return flag;
}