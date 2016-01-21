//
//  main.cpp
//  removeDuplicates

//  Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//
//  Do not allocate extra space for another array, you must do this in place with constant memory.
//
//  For example,
//  Given input array A = [1,1,2],
//
//  Your function should return length = 2, and A is now [1,2].
//
//  Created by Xingye Kan on 3/28/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

// variation: how to remove duplicates without sorting array?

#include <iostream>
using namespace std;

int removeDuplicates(int A[], int n) {
    
    if (n < 0 || n == 0) return 0;
    
   
    
    int i = 0;
    int count = 1;
    int temp = A[0];
    
    while (i < n - 1) {
        if (temp == A[i+1]){
            i++;
            continue;
        }
        
        
        for (int j = count; j < i+1; j++) {
            A[j] = A[i+1];
        }
        count++;
        temp = A[i+1];
        i++;
    }
    
    
    
    return count;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int nums[] = {1,1,2,2,3};
    
    
    int new_length = removeDuplicates(nums, 5);
    cout <<  new_length << endl;
    
    for (int i = 0; i < new_length; i++) {
        
        cout << nums[i] << " ";
    }
    
    return 0;
}
