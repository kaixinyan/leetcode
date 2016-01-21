//
//  main.cpp
//  summaryRanges
//
//  Created by Xingye Kan on 7/29/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    
    vector<string> answer;
    if(nums.size() == 0) return answer;
    
    string solution;
    
    
    
    
    
    int i = 0;
    int j = i+1;
    
    solution.push_back(to_string(nums[i]));
    
    if(j == nums.size()){
        answer.push_back(solution);
        return answer;
    }
    
    int left = nums[i];
    
    while(j < nums.size()){
        if(nums[j] - nums[i] == 1){
            ++i;
            j = i + 1;
        }
        else{
            if(nums[i] > left){
                solution.push_back(nums[i]);
            }
            i = j;
            left = nums[i];
            j = i + 1;
            answer.push_back(solution);
            while(solution.size() > 0) solution.pop_back();
        }
        
        
        
    }
    
    
    return answer;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {-1};
    vector<string> result = summaryRanges(nums);
    
    //cout << result;
    return 0;
}
