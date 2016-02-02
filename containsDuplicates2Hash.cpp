//
//  main.cpp
//  containsDuplicates2Hash
//
//  Created by Xingye Kan on 7/29/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    
    unordered_map<int,int> myMap;
    for(int i = 0;i < nums.size(); i++){
        if(myMap.find(nums[i]) != myMap.end() && myMap[nums[i]] >= i-k)
            return true;
        myMap[nums[i]] = i;
    }
    return false;
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1,2,3,4};
    
        int result;
        result = containsNearbyDuplicate(nums, 1);
        cout << result << endl;
    return 0;
    
}
