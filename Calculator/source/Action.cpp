#include <iostream>
#include <cmath> 

using namespace std;

char Action(char& action) {
    while (true) {
        cout << "ƒействие: ";
        cin >> action;
        cin.ignore(32767, '\n');
        if (action == '+' || action == '-' || action == '*' || action == '/' || action == '^') {
            return action;
        }
        cout << "\n¬ведите правильный знак" << endl;
        cout << "\n" << endl;
    }
    return action;
}