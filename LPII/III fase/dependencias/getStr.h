#pragma once

#include <string>
#include <limits>

using namespace std;
string getSTR(int n){
    char str[n];
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(str, n);
    return str;
}