//
//  main.cpp
//  plusOne
//
//  Created by Xingye Kan on 4/2/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

vector<int> plusOne(vector<int> &digits) {
    
    long int length = digits.size();
    
    
    
    
    int count = 0;
    
    for (long int i = length-1; i >= 0; i--) {
        if (digits[i] != 9) {
            break;
        }
        if (digits[i] == 9) {
            count++;
        }
    }
    
        
    if (count == 0) {
        digits[length-1]++;
    }
    
    else if (count < length) {
        for (long int i = length - 1; i >= length - count; i--) {
            digits[i] = 0;
        }
        digits[length-1-count]++;
    }
    
    else if (count == length){
        for (long int i = length - 1; i >= 1; i--) {
            digits[i] = 0;
        }
        digits[0] = 1;
        digits.push_back(0);
    }
    
    return digits;
}

    
    
    
    
    
    
    


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> A = {0};
    plusOne(A);
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << endl;
    }
    return 0;
}
