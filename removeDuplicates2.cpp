//
//  main.cpp
//  removeDuplicates2

//  Follow up for "Remove Duplicates":
//  What if duplicates are allowed at most twice?

//  For example,
//  Given sorted array A = [1,1,1,2,2,3],

//  Your function should return length = 5, and A is now [1,1,2,2,3].
//
//  Created by Xingye Kan on 4/6/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>
using namespace std;


int removeDuplicates(int A[], int n) {
    
    if (n <= 2) {
        return n;
    }
    
    int i = 0;
    int j = 1;
    
    int cnt = 0;
    
    while (j < n) {
        
    
    if (A[i] == A[j]) {
        j++;
        cnt = 0;
        while (A[i] == A[j] && j < n) {
            j++;
            cnt++;
        }
    }
    
     
    
    if (cnt > 0) {
        
        i = i + 2;
        if (i+cnt >= n) {
            return n - cnt;
        }
        for (int k = i; k < n - cnt; k++) {
            A[k] = A[k+cnt];
        }
        j = i + 1;
    }
    
    
        if (cnt == 0) {
            i = j;
            j++;
        }
        
        n = n - cnt;
        cnt = 0;
    
    
    
    
    }
    
    
    
    
    
    
    
    
    return n;
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[] = {0,0,1,1,1,1,2,2,2,4};
    
    
    int new_length = removeDuplicates(nums, 10);
    cout <<  new_length << endl;
    
    for (int i = 0; i < new_length; i++) {
        
        cout << nums[i] << " ";
    }

    return 0;
}
