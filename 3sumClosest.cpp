//
//  main.cpp
//  3sumClosest
//
//  Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

//  For example, given array S = {-1 2 1 -4}, and target = 1.

//  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//  Created by Xingye Kan on 4/15/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int threeSumClosest(vector<int> &nums, int target) {
    
    int solution;
    
    
    
    int dif;
    
    
    sort(nums.begin(), nums.end());
    
    long int length = nums.size();
    
    if(length <= 2) return solution;
    
    
    
    int i = 0;
    int j = i + 1;
    long int k = length - 1;
    
    solution = nums[i] + nums[j] + nums[k];
    
    dif = abs(nums[i] + nums[j] + nums[k] - target);
    
    while (i < k - 1) {
        if (abs(nums[i] + nums[j] + nums[k] - target) == 0) return target;
        if (abs(nums[i] + nums[j] + nums[k] - target) < dif) {
            dif = abs(nums[i] + nums[j] + nums[k] - target);
            solution = nums[i] + nums[j] + nums[k];
        }
        //if (abs(nums[i] + nums[j] + nums[k] - target) > dif) return solution;
        if (nums[i] + nums[j] + nums[k] < target) {
            j++;
            while (nums[j] == nums[j-1] && j < k) {
                j++;
            }
        }
        if (nums[i] + nums[j] + nums[k] > target) {
            k--;
            while (nums[k] == nums[k+1] && j < k) {
                k--;
            }
        }
        if (j >= k) {
            i++;
            while (nums[i] == nums[i-1]) {
                i++;
            }
            j = i + 1;
            k = length - 1;
            continue;
        }
        //solution = nums[i] + nums[j] + nums[k];
    }
    
    
    
    return solution;
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> numbers = {1,2,4,8,16,32,64,128};
    
    cout << threeSumClosest(numbers, 82) << endl;
    

    return 0;
}
