//
//  main.cpp
//  myAtoi

//  Implement atoi to convert a string to an integer.
//
//  Created by Xingye Kan on 6/15/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>
using namespace std;


int myAtoi(string &str) {
    
    long number = 0;
    
    long int l = str.length();
    
    if (l < 1) {
        return 0;
    }
    
    while (*str.begin() == ' ') {
        str.erase(str.begin());
    }
    
    int sign = 1;
    
    if (*str.begin() == '-') {
        sign = -1;
        str.erase(str.begin());
    }
    
    else if (*str.begin() == '+') {
        str.erase(str.begin());
    }
    
    int digit = 0;
    
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] <= '9' && str[i] >= '0') {
            ++digit;
        }
        else break;
    }
    
    
    
    if (digit == 0) return 0;
    
    
    
    for (int i = digit - 1; i >= 0; --i) {
        if (sign == 1)
        {number = number + pow(10,digit-1-i)*(str.at(i)-'0');
        if (number >= INT_MAX) {
            return INT_MAX;
        }}
        if (sign == -1) {
            number = number - pow(10,digit-1-i)*(str.at(i)-'0');
        
        if (number <= INT_MIN) {
            return INT_MIN;
        }}
    }
    
    //number = number * sign;
    
    
    if (number >= INT_MAX) {
        return INT_MAX;
    }
    
    if (number <= INT_MIN) {
        return INT_MIN;
    }
    
    return number;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    string str = "-1";
   cout << myAtoi(str);
}






