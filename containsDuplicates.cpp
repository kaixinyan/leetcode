//
//  main.cpp
//  containsDuplicates
//
//  Created by Xingye Kan on 6/15/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.

//  Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

#include <iostream>
#include <vector>
using namespace std;


bool containsDuplicate(vector<int>& nums) {
    if (nums.size() <= 1) return false;
    
    
    sort(nums.begin(),nums.end());
    
    int l = nums.size();
    
    for (int i = 0; i < l - 1; ++i){
        if (nums[i] == nums[i+1]) return true;
    }
    
    if (nums[l-2] == nums[l-1]) return true;
    
    return false;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
