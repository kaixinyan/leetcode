//
//  main.cpp
//  containsDuplicates2
//
//  Created by Xingye Kan on 6/15/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.

//  Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

#include <iostream>
#include <vector>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    
    int l = nums.size();
    
    
    
    if (k < 1) return false;
    if (l <= 1) return false;
    
    
    
    for (int i = 0; i < l; ++i){
        for (int j = i + 1; j < l; ++j) {
            if (nums[i] == nums[j] && j - i <= k) return true;
        }
    }
    
    
    
    
    
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1,2,1};
    unordered_map<int,int> myMap;
    
    for(int i = 0; i < nums.size(); ++i){
        myMap[nums[i]] = i;
    }
//    int result;
//    result = containsNearbyDuplicate(nums, 1);
//    cout << result << endl;
    return 0;
}
