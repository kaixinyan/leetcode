//
//  main.cpp
//  addBinary
//
//  Created by Xingye Kan on 8/4/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


string addBinary(string a, string b) {
    
    // find lengths of both strings in order to access their last digits
    
    int la = a.size();
    int lb = b.size();
    
    if(la == 0) return b;
    
    if(lb == 0) return a;
    
    // get indices of their last digits
    
    int ia = la - 1;
    int ib = lb - 1;
    
    // find the length after addition
    
    int l = max(la,lb) + 1;
    
    string aPlusb;
    
    // adding
    
    while(ia > 0 && ib > 0){
    
        if(a[ia] == 0 || b[ib] == 0) aPlusb[l-1] = a[ia] + b[ib];
    
        else{
           aPlusb[l-1] = 0;
           ++aPlusb[l];
        }
    
        --l;
        --ia;
        --ib;
        
    }
    
    
    if (ia == 0 && ib == 0) {
        return aPlusb;
    }
    
    if (ia == 0) {
        while (ib > 0) {
            aPlusb[l] = b[ib];
            --l;
            --ib;
        }
    }
    else{
        while (ib > 0) {
            aPlusb[l] = b[ib];
            --l;
            --ib;
        }
    }
    
    
    
    return aPlusb;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
