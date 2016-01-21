//
//  main.cpp
//  leetcode
//
//  Created by Xingye Kan on 3/17/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
    void rotate1(vector<int> &nums, int n, int k) {
        
        if(k < 0 || k == n) return;
        if(k > n) k = k%n;
        
    
        int temp; int count = 0;
        
        while(count < k)
        
        {
            temp = nums[n-1];
            for (int j = 0; j < n-1; j++){
                nums[n-1-j] = nums[n-1-j-1];
            }
            nums[0] = temp;
            count++;
        }
        
    }
//};



void rotatek(vector<int> &nums, int n, int k) {
    
    if(k < 0 || k == n || n < 0) return;
    if(k > n) k = k%n;
    
    
    int temp; int count = 0;
    
    int current_index = 0; // start rotation from beginning of the sequence
    int current = nums[0];  // value that is going to be rotated in the first loop
    
    int next_index;    // destination for current number to rotate to
    int distance = 0;
    
    
    
    
    
    while(count < n){
        
        next_index = (current_index + k)%n; // calculate destination based on starting address
        temp = nums[next_index];          // record number already at destination elsewhere to avoid value missing
        nums[next_index] = current;     // update value at destination by current value
        
        current_index = next_index;  // proceed to the address of next value that needs to be rotated
        current = temp; // value that is going to be rotated in the next loop: value that is stored at destination before current rotation
        
        distance = (distance + k)%n;
        if (distance == 0){current_index = (current_index + 1)%n; // if k is a factor of n, current_index will go back to the      beginning address of the sequence, i.e, distance == 0. In this case, we have to shift the current address by 1 in order to update every value in the original sequence
            current = nums[current_index];}
        
        count++;
    }
    
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> num = {1,2,3,4,5,6};
    rotatek(num, 6, 2);
    
    for (int i = 0; i < 6; i++) {
        
        cout << num[i] << endl;
        
    }
    return 0;
}
