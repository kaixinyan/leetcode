//
//  main.cpp
//  removeElement
//
//  Created by Xingye Kan on 3/25/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
int removeElement(int A[], int n, int elem) {
    
    if (n <= 0) return 0;
    
    

    
    int count = 0;
    int i = 0;
    int temp;
    
    while (i < n - count){
        while(A[i] == elem){
            if (n-1-count == i) return n - count - 1;
            temp = A[n-1-count];
            A[n-1-count] = A[i];
            A[i] = temp;
            count++;
        }
        i = i + 1;
    }
    return n - count;
}








int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[] = {2};
    cout << removeElement(nums, 1, 2) << endl;

    for (int i = 0; i < 1; i++) {
    
        cout << nums[i] << endl;
    }
    
    return 0;
}

