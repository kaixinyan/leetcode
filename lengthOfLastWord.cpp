//
//  main.cpp
//  lengthOfLastWord
//
//  Created by Xingye Kan on 8/4/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {
    
    
    int length = s.size();
    
    int count = 0;
    
    if(length == 0) return 0;
    
    int i = length - 1;
    
    while(i >= 0){
        if(s[i] == ' ') return count;
        
        else{
            ++count;
            --i;
        }
    }
    
    return count;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
