//
//  main.cpp
//  palindromeNumber
//
//  Created by Xingye Kan on 6/15/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

// stoi convert integer to string

#include <iostream>
//#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

bool isPalindrome(int x) {
    
    string number;          // string which will contain the number x
    
    ostringstream convert;   // stream used for the conversion
    
    convert << x;      // insert the textual representation of 'number' in the characters in the stream
    
    number = convert.str();   // set 'number' to the contents of the stream
    
    while (number.length() > 1) {
        if (number[0] == number[number.length()-1]) {
            number.erase(number.begin());
            number.pop_back();
        }
        else return false;
    }
    
    return true;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
