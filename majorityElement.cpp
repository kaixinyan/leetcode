//
//  main.cpp
//  majorityElement
//  Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
//  You may assume that the array is non-empty and the majority element always exist in the array.
//
//  Created by Xingye Kan on 4/3/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

// moore's vote
// Note: There are at most 1 majority element. Without the assumption in the problem, we need to count how many times maj actually occurs since it may not exist.

int majorityElement(vector<int> &num) {
    
    int flag = 0;
    long int length = num.size();
    
    long int maj = num[0];
    
    
    for (long int i = 0; i < length; i++) {
        if (num[i] == maj) {
            flag++;
        }
        else flag--;
        if (flag == 0) {
            maj = num[i];
            flag = 1;
        }
    }
    
    
    return maj;
}


// variation: what about finding the element appearing more than ⌊ n/3 ⌋, ⌊ n/4 ⌋ times?
//  If an element appears more than n/3 times, then if I remove any three distinct elements from array then that element still appears more than one third of remaining elements. Start scanning the array from start and maintain three variables and also counters for them. When u see three different variables decrement counters by one otherwise increment respective counters. After the end the variables with non zero counters are your answer.

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> A = {6,5,5};
    cout << majorityElement(A) << endl;
    
    return 0;
}
